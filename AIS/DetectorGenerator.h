#pragma once
#include "Detector.h"

namespace AIS
{

class DetectorGenerator
{
public:
	virtual ~DetectorGenerator();

	virtual Detector* generate() const = 0;

	virtual Detector* operator()() const;
};

typedef std::shared_ptr<DetectorGenerator> DetectorGeneratorPtr;
} // namespace AIS
