#pragma once
#include "AIS/Detector.h"

namespace IDS
{

class IDS 
{
public:
	virtual ~IDS();

public:
	virtual void start() = 0;
	virtual void stop() = 0;
};

} // namespace IDS