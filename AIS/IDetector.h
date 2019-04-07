#pragma once
#include "IAntigen.h"
#include <memory>
namespace AIS
{

class IDetector
{
public:
	virtual bool match(const IAntigen* antigen) const = 0;
};

typedef std::shared_ptr<IDetector> DetectorPtr;
} // namespace AIS
