#define _CRT_SECURE_NO_WARNINGS
#include "IDS/KDDIDS.h"
#include <iostream>
#include <iomanip>
#include <fstream>
int main(int argc, char** argv) 
{
	IDS::KDDIDS ids("../KDDCup99Dataset/kddcup.data_10_percent_corrected", "../KDDCup99Dataset/kddcup.data.corrected", 4);

	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", timeinfo);
	std::string time(buffer);
	std::ofstream off("../CSV/With Clonal Selection without reset " + time + ".csv");


	ids.start();
	std::cout << "KDD IDS started!" << std::endl;
	while (true) {
		auto errors = ids.get_stats();
		system("cls");
		std::cout << std::setprecision(2) << std::fixed;
		std::cout << "Correctly recognized as victim:   " << errors[1] / 1e6 << "M" << "\t" << ( errors[1] + errors[3] ? errors[1] / double(errors[1] + errors[3])*100 : 100 ) << "%" << std::endl;
		std::cout << "Correctly recognized as legit:    " << errors[2] / 1e6 << "M" << "\t" << ( errors[0] + errors[2] ? errors[2] / double(errors[0] + errors[2]) * 100 : 100 ) << "%" << std::endl;
		std::cout << "Incorrectly recognized as victim: " << errors[0] / 1e6 << "M" << "\t" << ( errors[0] + errors[2] ? errors[0] / double(errors[0] + errors[2]) * 100 : 0 ) << "%" << std::endl;
		std::cout << "Inorrectly recognized as legit:   " << errors[3] / 1e6 << "M" << "\t" << ( errors[1] + errors[3] ? errors[3] / double(errors[1] + errors[3]) * 100 : 0 ) << "%" << std::endl;
		std::cout << "Total: " << (errors[0] + errors[1] + errors[2] + errors[3]) / 1e6 << "M" << std::endl;
		off << errors[1] << "," << errors[2] << "," << errors[0] << "," << errors[3] << std::endl;
			
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}