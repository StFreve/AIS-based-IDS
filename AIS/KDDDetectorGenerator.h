#pragma once
#include "DetectorGenerator.h"
#include "KDDDetector.h"

#include <random>

namespace AIS
{

class KDDDetectorGenerator : public DetectorGenerator
{
public:
	KDDDetectorGenerator();
	~KDDDetectorGenerator();

	virtual KDDDetector* generate() const override;
private:
	mutable std::random_device rd_;
	mutable std::default_random_engine generator_;
};


} // namespace AIS

