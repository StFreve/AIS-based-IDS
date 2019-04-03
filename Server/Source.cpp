#include "IDS/IDS.h"
#include <iostream>
int main(int argc, char** argv) 
{
	IDS ids;
	std::cout << "IDS starting\n";
	ids.start();
	std::cout << "IDS finished\n";
}