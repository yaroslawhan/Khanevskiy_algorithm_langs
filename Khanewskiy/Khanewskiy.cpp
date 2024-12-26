#include <unordered_map>
#include <vector>
#include "headers/pipeClass.h"
#include "headers/compressorStationClass.h"
#include "headers/batchProcessing.h"
#include "headers/auxiliaryFuncs.h"

#include <iostream>
#include <string>
#include <fstream>
#include <type_traits>

//template <typename T>
//std::unordered_map<int, T> selectElements(std::unordered_map<int, T>& unordered_map) {
//	std::unordered_map<int, T> selectedElements;
//	short int action;
//	while (1) {
//		/*std::cout << "1. Search " << (T == Pipe) ? "pipes\n" : "compressor stations\n",
//			"2. Coming soon\n\n",
//		"Please choose an option: ";*/
//		action = choosingAction({ "Options:\n\n", "1. Selecting the search criteria", "2. Selecting an action with dedicated elements", "3. Display selected elements", "0. Back to the menu without changes\n", "Please choose an option : " });
//		if (!(action >= 0 && action <= 3))
//			clearCin();
//		else {
//			switch (action) {
//			case 0:
//				std::cout << "\n\n";
//				return std::unordered_map<int, T>{};
//				break;
//			case 1: {
//				bool criteriaChoosingMenuFlag = true;
//				while (criteriaChoosingMenuFlag) {
//					if constexpr (std::is_same_v<T, Pipe>) action = choosingAction({ "Select the search criteria:\n\n", "1. By name", "2. On the basis of 'under repair'", "0. Back to the menu\n", "Please choose an option : " });
//					if (action < 0 || action > 2)//(!(action >= 0 && action <= 2))
//						clearCin();
//					else {
//						bool flag = false;
//						switch (action) {
//						case 0:
//							criteriaChoosingMenuFlag = false;
//							break;
//						case 1: {
//							std::cout << "Enter the name of the ";
//							if constexpr (std::is_same_v<T, Pipe>) std::cout << "pipe: ";
//							else if constexpr (std::is_same_v<T, CompressorStation>) std::cout << "compressor station: ";
//							//std::cout << "Enter the name of the " << ((std::is_same_v<T, Pipe>) ? "pipe: " : "compressor station: ");
//							std::string name;
//							getline(std::cin >> std::ws, name);
//							if constexpr (std::is_same_v<T, Pipe>) {
//								for (int i = 0; i < unordered_map.size(); i++) {
//									if ((name == unordered_map[i].get_name()) && !(selectedElements[i] == unordered_map[i])) {
//										selectedElements[i] = unordered_map[i];
//										flag = true;
//									}
//								}
//							}
//							if constexpr (std::is_same_v<T, CompressorStation>) {
//								for (int i = 0; i < unordered_map.size(); i++) {
//									if (name == unordered_map[i].get_name() && (selectedElements[i] != unordered_map[i])) {
//										selectedElements[i] = unordered_map[i];
//										flag = true;
//									}
//								}
//							}
//
//							if constexpr (std::is_same_v<T, Pipe>) std::cout << "\n\nPipe's choosing was ";
//							else if constexpr (std::is_same_v<T, CompressorStation>) std::cout << "Compressor station's choosing was ";
//							if (flag) std::cout << "successful!\n\n";
//							else std::cout << "failed\n\n";
//
//							break;
//						}
//							  //std::cout << "\n\n" << (constexpr (std::is_same_v<T, Pipe>) ? "Pipe's " : "Compressor station's ") << "choosing was " << ((flag) ? "successful!\n\n\n" : "failed\n\n\n");
//						case 2:
//							if constexpr (std::is_same_v<T, Pipe>) {
//								bool isRepairing;
//								while (true) {
//									std::cout << "Choose pipes status (0 - in repairing, 1 - not in repairing): ";
//									std::cin >> isRepairing;
//
//									if (checkCinError()) {
//										if (std::cin.good()) {
//											break;
//										}
//									}
//								}
//								for (int i = 0; i < unordered_map.size(); i++) {
//									if ((isRepairing == unordered_map[i].get_state()) && (selectedElements[i] != unordered_map[i])) {
//										selectedElements[i] = unordered_map[i];
//										flag = true;
//									}
//								}
//							}
//
//							if constexpr (std::is_same_v<T, CompressorStation>) {
//								short int WorkshopsPercentage;
//								while (true) {
//									std::cout << "\nEnter the percentage of unused workshops: ";
//									std::cin >> WorkshopsPercentage;
//
//									if (checkCinError()) {
//										if (WorkshopsPercentage < 0) {
//											std::cout << "ERROR. The percentage of unused workshops can`t be less than 0\n";
//										}
//										else if (WorkshopsPercentage > 100) {
//											std::cout << "ERROR. The percentage of unused workshops can`t be more than 100\n";
//										}
//										else {
//											break;
//										}
//									}
//								}
//								for (int i = 0; i < unordered_map.size(); i++) {
//									if ((WorkshopsPercentage == unordered_map[i].get_WorkshopsPercentage()) && (selectedElements[i] != unordered_map[i])) {
//										selectedElements[i] = unordered_map[i];
//										flag = true;
//									}
//								}
//							}
//							std::cout << "\n\n" << ((std::is_same<T, Pipe>::value) ? "Pipe's " : "Compressor station's ") << "choosing was " << ((flag) ? "successful!\n\n\n" : "failed\n\n\n");
//							break;
//						}
//					}
//				}
//				break;
//			}
//			case 2:
//				return selectedElements;
//				break;
//			case 3:
//				if (selectedElements.size() > 0) {
//					std::cout << "\n\nSelected elements:\n\n";
//					if constexpr (std::is_same_v<T, Pipe>) {
//						for (int i = 0; i < selectedElements.size(); i++) {
//							if (selectedElements[i].get_name() != "")
//								selectedElements[i].showPipe();
//						}
//					}
//					if constexpr (std::is_same_v<T, CompressorStation>) {
//						for (int i = 0; i < selectedElements.size(); i++)
//							selectedElements[i].showCs();
//					}
//				}
//				else {
//					std::cout << "\n\nThere are no selected elements\n\n";
//				}
//				break;
//			}
//		}
//
//	}
//}

int main()
{

	std::unordered_map<int, Pipe> pipe;
	bool pipeExist = false;
	int pipeMaxID = -1;

	std::unordered_map<int, CompressorStation> cs;
	bool csExist = false;
	int csMaxID = -1;

	unsigned short int action; // Action in menu

	while (1) // Infinity cycle causes a menu
	{
		showMenu();

		std::cin >> action;

		if (!(std::cin.good() && action >= 0 && action <= 7)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n\n";

		}
		else {
			switch (action) {
			case 0:
				return 0;

			case 1:
				pipe[pipeMaxID].addPipe();
				std::cout << "New pipe added successfully!\n\n";
				pipeExist = true;
				pipeMaxID += 1;
				break;
			case 2:
				cs[cs.size()].addCs();
				std::cout << "New compressor station added successfully!\n\n";
				csExist = true;
				csMaxID += 1;
				break;
			case 3:
				if (pipeExist) {
					std::cout << "\n\nInformation about pipes:\n\n";
					for (int i = 0; i < pipe.size(); i++)
						pipe[i].showPipe();
				}
				else {
					std::cout << "Pipe does not exist\n\n";
				}
				if (csExist) {
					std::cout << "Information about compressor stations:\n";
					for (int i = 0; i < cs.size(); i++)
						cs[i].showCs();
				}
				else {
					std::cout << "Compressor station does not exist\n\n";
				}
				break;
			case 4:
				if (pipeExist) {
					if (!(batchProcessing(pipe, pipeMaxID))) clearCin();
				}
				else {
					std::cout << "Pipe does not exist\n\n";
				}
				break;
			case 5:
				if (csExist) {
					if (!(batchProcessing(cs, pipeMaxID))) clearCin();
				}
				else {
					std::cout << "Compressor station does not exist\n\n";
				}
				break;
			case 6: {
				std::ofstream ofile;
				ofile.open("data.txt");

				ofile << pipe.size() << "\n";
				if (pipeExist) {
					for (int i = 0; i < pipe.size(); i++)
						pipe[i].savePipe(ofile);
					std::cout << "The pipes was successfully saved!\n\n";
				}
				else
					std::cout << "The pipe does not exist\n\n";

				ofile << cs.size() << "\n";
				if (csExist) {
					for (int i = 0; i < cs.size(); i++)
						cs[i].saveCs(ofile);
					std::cout << "The compressor stations was successfully saved!\n\n";
				}
				else
					std::cout << "The compressor station does not exist\n\n";

				ofile.close();
				break;
			}
			case 7: {
				std::ifstream ifile;
				ifile.open("data.txt");

				int pipeCount;
				ifile >> pipeCount;
				if (pipeCount > 0) {
					pipeExist = true;
					for (int i = 0; i < pipeCount; i++) {
						pipe[i].loadPipe(ifile);
						pipeMaxID += 1;
					}
					std::cout << "The pipes was successfully loaded!\n\n";
				}
				else
					std::cout << "Pipe does not exist\n\n";

				int csCount;
				ifile >> csCount;
				if (csCount > 0) {
					csExist = true;
					for (int i = 0; i < csCount; i++)
						cs[i].loadCs(ifile);
					std::cout << "The compressor stations was successfully loaded!\n\n";
				}
				else
					std::cout << "The compressor station does not exist\n\n";

				ifile.close();
				break;
			}
			}
		}
	}
	return 0;
}