#include "Detector.h"

namespace AIS
{
AIS::Detector::Detector()
	: stimulated_counter_(0)
{
}

AIS::Detector::~Detector()
{
}

size_t AIS::Detector::stimulated_counter() const
{
	return stimulated_counter_;
}

void AIS::Detector::reset_stimulatated_counter()
{
	stimulated_counter_ = 0;
}

void AIS::Detector::stimulated() const {
	++stimulated_counter_;
}

} // namespace AIS
