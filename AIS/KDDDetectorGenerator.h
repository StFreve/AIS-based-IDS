#pragma once
#include "KDDDetector.h"
#include <initializer_list>
#include <random>

namespace AIS
{

class KDDDetectorGenerator
{
public:
	KDDDetectorGenerator();
	~KDDDetectorGenerator();

	KDDDetector* get_next();

private:
	std::random_device rd_;
	std::default_random_engine generator_;
};


} // namespace AIS

