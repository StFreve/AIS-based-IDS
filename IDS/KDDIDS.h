#pragma once
#include "AIS/KDDDetector.h"
#include "AIS/KDDDetectorGenerator.h"
#include "AIS/KDDAntigen.h"
#include "AIS/Utilities.h"
#include <memory>
#include <string>
#include <set>

namespace IDS
{

class KDDIDS
{
public:
	KDDIDS(const std::string& kdd_training_set, const std::string& kdd_full_set);
	~KDDIDS();

	void start();

private:
	void training();
	void emulate_activity();

private:
	std::vector<AIS::DetectorPtr> detectors_;

	std::string kdd_training_set_;
	std::string kdd_full_set_;
};

}