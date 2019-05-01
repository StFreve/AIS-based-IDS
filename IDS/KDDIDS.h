#pragma once
#include "IDS.h"

#include "AIS/KDDDetector.h"
#include "AIS/KDDDetectorGenerator.h"
#include "AIS/KDDAntigen.h"
#include "AIS/KDDReader.h"

#include <memory>
#include <string>
#include <set>
#include <queue>

#include <thread>
#include <mutex>
#include <condition_variable>
namespace IDS
{

class KDDIDS : public IDS
{
public:
	KDDIDS(const std::string& kdd_training_set, const std::string& kdd_full_set, size_t thread_count);
	~KDDIDS();

	virtual void start() override;
	virtual void stop() override;

	std::vector<size_t> get_stats() const;
private:
	class ActivityEmulator
	{
	public:
		ActivityEmulator(const std::string & kdd_full_set_path, size_t maximal_queue_size, size_t chunk_size);
		~ActivityEmulator();

		void start();
		void stop();

		void take_packet_chunk(AIS::KDDReader::AntigenWithStatusList& chunk);
	private:
		void run();

		std::queue<AIS::KDDReader::AntigenWithStatusList> chunk_queue_;
		std::mutex chunk_queue_mutex_;
		std::thread thread_;

		AIS::KDDReader kdd_reader_;
		size_t minimal_queue_size_;
		size_t maximal_queue_size_;
		size_t chunk_size_;
		std::mutex sync_mutex_;
		std::mutex running_mutex_;
		bool running_;
	};

private:
	void training();
	void process_packets();

private:
	typedef std::vector<AIS::DetectorPtr> detectors_t;
	typedef std::vector<AIS::AntigenPtr> antigens_t;

	detectors_t detectors_;
	antigens_t self_antigens_;
	std::vector<size_t> stats_;
	AIS::DetectorGeneratorPtr detector_generator_;

	ActivityEmulator activity_emulator_;
	std::vector<std::thread> threads_;

	bool running_;

	mutable std::mutex sync_mutex_;
	mutable std::mutex detectors_mutex_;
	mutable std::mutex stats_mutex_;
};

}