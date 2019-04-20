#include "KDDIDS.h"
#include "AIS/Algorithms.h"
#include <algorithm>
namespace IDS
{

KDDIDS::KDDIDS(const std::string & kdd_training_set, const std::string & kdd_full_set)
	: kdd_training_set_(kdd_training_set)
	, kdd_full_set_(kdd_full_set_)
{
}

KDDIDS::~KDDIDS()
{
}

void KDDIDS::start()
{
}

void KDDIDS::training()
{
	AIS::KDDDetectorGenerator kdd_generator;
	AIS::KDDReader kdd_reader(kdd_training_set_);
	auto antigens = kdd_reader.read_all();
	std::vector<AIS::AntigenPtr> self_antigens;
	std::transform(antigens.begin(), antigens.end(), std::back_inserter(self_antigens), [](const auto& antigen) { return antigen.first; });
	
	size_t DetectorsCount = 40;
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
}

}