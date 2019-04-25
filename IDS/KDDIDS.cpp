#include "KDDIDS.h"
#include "AIS/Algorithms.h"
#include "AIS/KDDReader.h"

#include <algorithm>
#include <iostream>

namespace IDS
{

KDDIDS::KDDIDS(const std::string & kdd_training_set, const std::string & kdd_full_set, size_t thread_count)
	: kdd_training_set_(kdd_training_set)
	, activity_emulator_(kdd_full_set, thread_count*2, 10000)
	, running_(false)
	, threads_(thread_count)
	, stats_(4, 0)
{
}

KDDIDS::~KDDIDS()
{
	stop();
}

void KDDIDS::start()
{
	std::lock_guard<std::mutex> lock(sync_mutex_);

	if (running_ == false) {
		running_ = true;
		activity_emulator_.start();
		training();
		for (size_t i = 0; i < threads_.size(); ++i) {
			threads_[i] = std::thread(&KDDIDS::process_packets, this);
		}
	}
}

void KDDIDS::stop()
{
	std::lock_guard<std::mutex> lock(sync_mutex_);

	if (running_) {
		running_ = false;
		activity_emulator_.stop();
		for (auto& thread : threads_) {
			thread.join();
		}
	}
}

std::vector<size_t> KDDIDS::get_stats() const
{
	std::lock_guard<std::mutex> lock(stats_mutex_);
	return stats_;
}

void KDDIDS::training()
{
	AIS::KDDDetectorGenerator kdd_generator;
	AIS::KDDReader kdd_reader(kdd_training_set_);
	auto antigens = kdd_reader.read_all();
	std::vector<AIS::AntigenPtr> self_antigens;
	for (const auto& kdd_antigen : antigens) {
		if (kdd_antigen.second) {
			self_antigens.push_back(kdd_antigen.first);
		}
	}

	size_t DetectorsCount = 2000;
	while (detectors_.size() < DetectorsCount) {
		AIS::DetectorPtr kdd_detector(kdd_generator.generate());
		if (AIS::Algorithms::NegativeSelection(kdd_detector, self_antigens))
		{
			detectors_.push_back(kdd_detector);
		}
	}
}

void KDDIDS::process_packets()
{
	while (running_) {
		size_t errors[4] = {};
		AIS::KDDReader::AntigenWithStatusList antigens;
		activity_emulator_.take_packet_chunk(antigens);
		for (const auto& antigen : antigens) {
			bool detected = false;
			for (const auto& detector : detectors_) {
				if (detector->match(antigen.first.get())) {
					detected = true;
				}
			}
			if (detected && antigen.second) {
				++errors[0];
			}
			else if (detected && !antigen.second) {
				++errors[1];
			}
			else if (!detected && antigen.second) {
				++errors[2];
			}
			else if (!detected && !antigen.second) {
				++errors[3];
			}
		}

		if (antigens.empty()) {
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		else {
			std::lock_guard<std::mutex> lock(stats_mutex_);
			for (size_t i = 0; i < 4; ++i) {
				stats_[i] += errors[i];
			}
		}
	}
}

KDDIDS::ActivityEmulator::ActivityEmulator(const std::string & kdd_full_set_path, size_t maximal_queue_size, size_t chunk_size)
	: kdd_reader_(kdd_full_set_path)
	, maximal_queue_size_(maximal_queue_size)
	, chunk_size_(chunk_size)
	, running_(false)
{
}

KDDIDS::ActivityEmulator::~ActivityEmulator()
{
	stop();
}

void KDDIDS::ActivityEmulator::start()
{
	std::lock_guard<std::mutex> lock(sync_mutex_);

	if (running_ == false) {
		running_ = true;
		thread_ = std::thread(&KDDIDS::ActivityEmulator::run, this);
	}
}

void KDDIDS::ActivityEmulator::stop()
{
	std::lock_guard<std::mutex> lock(sync_mutex_);

	if (running_) {
		running_ = true;
		thread_.join();
	}
}

void KDDIDS::ActivityEmulator::take_packet_chunk(AIS::KDDReader::AntigenWithStatusList & chunk)
{
	std::lock_guard<std::mutex> lock(chunk_queue_mutex_);

	if (chunk_queue_.empty()) {
		return;
	}

	chunk.swap(chunk_queue_.front());
	chunk_queue_.pop();
}

void KDDIDS::ActivityEmulator::run()
{
	while (running_ && !kdd_reader_.eof()) {

		std::unique_lock<std::mutex> lock(chunk_queue_mutex_);

		if (chunk_queue_.size() < maximal_queue_size_) {
			lock.unlock();
			auto chunk = kdd_reader_.read_chunk(chunk_size_);
			lock.lock();

			chunk_queue_.push(chunk);
		}
		else {
			lock.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

}