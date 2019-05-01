#include "Detector.h"

namespace AIS
{
AIS::Detector::Detector()
	: stimulated_counter_(0)
{
}

Detector::Detector(const Detector & rhd)
	: stimulated_counter_(rhd.stimulated_counter_.load())
{
}

AIS::Detector::~Detector()
{
}

bool Detector::match(const Antigen * antigen) const
{
	if (match_impl(antigen)) {
		++stimulated_counter_;
		return true;
	}
	return false;
}
size_t AIS::Detector::stimulated() const
{
	return stimulated_counter_;
}

} // namespace AIS
