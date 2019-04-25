#include "IDS/KDDIDS.h"
#include <iostream>
#include <fstream>
int main(int argc, char** argv) 
{
	IDS::KDDIDS ids("../KDDCup99Dataset/kddcup.data_10_percent_corrected", "../KDDCup99Dataset/kddcup.data.corrected", 4);
	ids.start();
	std::cout << "KDD IDS started!" << std::endl;
	while (true) {
	/*	std::string command;
		std::cin >> command;
		if (command == "exit") {
			return 0;
		}
		if (command == "info")*/ {
			auto errors = ids.get_stats();
			system("cls");
			std::cout << "Correctly recognized as victim: " << errors[1] << std::endl;
			std::cout << "Correctly recognized as legit: " << errors[2] << std::endl;
			std::cout << "Incorrectly recognized as victim: " << errors[0] << std::endl;
			std::cout << "Inorrectly recognized as legit: " << errors[3] << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
}