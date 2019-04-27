#include "DetectorGenerator.h"

namespace AIS
{

DetectorGenerator::~DetectorGenerator()
{
}

Detector * DetectorGenerator::operator()() const
{
	return generate();
}

} // namespace AIS
