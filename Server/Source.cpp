#include "IDS/IDS.h"
#include "AIS/KDDDetectorGenerator.h"
#include <iostream>
int main(int argc, char** argv) 
{
	AIS::KDDDetectorGenerator generator;
	AIS::KDDDetector* detector = generator.get_next();
	IDS::IDS ids;
	ids.start();
}