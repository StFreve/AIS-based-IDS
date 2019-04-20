#include "KDDIDS.h"
#include "AIS/Algorithms.h"
#include "AIS/KDDReader.h"

#include <algorithm>
#include <iostream>

namespace IDS
{

KDDIDS::KDDIDS(const std::string & kdd_training_set, const std::string & kdd_full_set)
	: kdd_training_set_(kdd_training_set)
	, kdd_full_set_(kdd_full_set)
{
}

KDDIDS::~KDDIDS()
{
}

void KDDIDS::start()
{
	training();
	emulate_activity();
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
	
	size_t DetectorsCount = 4000;
	while (detectors_.size() < DetectorsCount) {
		AIS::DetectorPtr kdd_detector(kdd_generator.get_next());
		if (AIS::Algorithms::NegativeSelection(kdd_detector, self_antigens))
		{
			detectors_.push_back(kdd_detector);
		}
	}
}

void KDDIDS::emulate_activity()
{
	AIS::KDDReader kdd_reader(kdd_full_set_);

	size_t errors[4] = {};
	while (kdd_reader.eof() == false) {
		auto antigens = kdd_reader.read_chunk(200);
		for (const auto& antigen : antigens) {
			bool detected = false;
			for (const auto& detector : detectors_) {
				if (detector->match(antigen.first.get())) {
					detected = true;
					break;
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
		system("cls");
		std::cout << "Correctly recognized as victim: " << errors[1] << std::endl;
		std::cout << "Correctly recognized as legit: " << errors[2] << std::endl;
		std::cout << "Incorrectly recognized as victim: " << errors[0] << std::endl;
		std::cout << "Inorrectly recognized as legit: " << errors[3] << std::endl;
	}
}

}