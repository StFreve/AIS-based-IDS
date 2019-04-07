#pragma once
#include "IAntigen.h"

namespace AIS
{

class IDetector
{
public:
	virtual bool match(const IAntigen& antigen) const = 0;
};

} // namespace AIS
