#pragma once
#include "Detector.h"

namespace AIS
{

class DetectorGenerator
{
public:
	virtual ~DetectorGenerator();

	virtual Detector* generate() const = 0;
};

typedef std::shared_ptr<DetectorGenerator> DetectorGeneratorPtr;
} // namespace AIS
