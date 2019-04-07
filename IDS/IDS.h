#pragma once
#include "IIDS.h"
#include "AIS/IDetector.h"

namespace IDS
{

class IDS : public IIDS
{
public:
	IDS();
	~IDS();

public:
	void start();

};

} // namespace IDS