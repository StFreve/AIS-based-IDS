#pragma once
#include "IIDS.h"
#include "AIS/IDetector.h"
class IDS :	public IIDS
{
public:
	IDS();
	~IDS();

public:
	void start();

};

