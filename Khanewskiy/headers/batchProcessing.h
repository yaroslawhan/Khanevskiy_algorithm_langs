#pragma once

#include <unordered_map>
#include <vector>
#include "headers/pipeClass.h"
#include "headers/compressorStationClass.h"
#include "headers/auxiliaryFuncs.h"

#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
bool editElements(std::unordered_map<int, T>& unordered_map, std::vector<int> selectedElements) {
	if (selectedElements.size() > 0) {
		if constexpr (std::is_same_v<T, Pipe>) {
			for (int i = 0; i < selectedElements.size(); i++) {
				std::cout << "\n\nEditing " << unordered_map[selectedElements[i]].get_name() << "\n";
				unordered_map[selectedElements[i]].editPipe();
			}
		}

		if constexpr (std::is_same_v<T, CompressorStation>) {
			for (int i = 0; i < selectedElements.size(); i++) {
				std::cout << "\n\nEditing " << unordered_map[selectedElements[i]].get_name() << "\n";
				unordered_map[selectedElements[i]].editCs();
			}
		}

		std::cout << "The elements was successfully edited!\n\n";
		return true;
	}
	else {
		std::cout << "There are no selected elements!\n\n";
		return false;
	}
}

template <typename T>
bool removeElements(std::unordered_map<int, T>& unordered_map, std::vector<int> selectedElements) {
	if (selectedElements.size() > 0) {
		for (int i = 0; i < selectedElements.size(); i++) {
			unordered_map.erase(selectedElements[i]);
		}

		std::cout << "The elements was successfully removed!\n\n";
		return true;
	}
	else {
		std::cout << "There are no selected elements!\n\n";
		return false;
	}
}

template <typename T>
bool batchProcessing(std::unordered_map<int, T>& unordered_map, const int& maxID) {
	std::vector<int> selectedElements;
	short int action;
	while (1) {
		action = choosingAction({ "Options:\n\n", "1. Selecting the search criteria", "2. Selecting an action with dedicated elements", "3. Display selected elements", "0. Back to the menu without changes\n", "Please choose an option : " });
		if (!(action >= 0 && action <= 3))
			clearCin();
		else {
			switch (action) {
			case 0:
				std::cout << "\n\n";
				return true;
				break;
			case 1: {
				bool criteriaChoosingMenuFlag = true;
				while (criteriaChoosingMenuFlag) {
					if constexpr (std::is_same_v<T, Pipe>) action = choosingAction({ "Select the search criteria:\n\n", "1. By name", "2. On the basis of 'under repair'", "0. Back to the menu\n", "Please choose an option : " });
					if constexpr (std::is_same_v<T, CompressorStation>) action = choosingAction({ "Select the search criteria:\n\n", "1. By name", "2. By percentage of unused workshops", "0. Back to the menu\n", "Please choose an option : " });

					if (action < 0 || action > 2)
						clearCin();
					else {
						bool flag = false;
						switch (action) {
						case 0:
							criteriaChoosingMenuFlag = false;
							break;
						case 1: {
							std::cout << "Enter the name of the ";
							if constexpr (std::is_same_v<T, Pipe>) std::cout << "pipe: ";
							else if constexpr (std::is_same_v<T, CompressorStation>) std::cout << "compressor station: ";
							std::string name;
							getline(std::cin >> std::ws, name);

							for (int i = 0; i <= maxID; i++) {
								if ((name == unordered_map[i].get_name()) && !(checkElementPresenceInMassive(i, selectedElements))) {
									selectedElements.push_back(i);
									flag = true;
								}
							}
							/*if constexpr (std::is_same_v<T, CompressorStation>) {
								for (int i = 0; i < unordered_map.size(); i++) {
									if (name == unordered_map[i].get_name() && !(selectedElements[i] == unordered_map[i])) {
										selectedElements[i] = unordered_map[i];
										flag = true;
									}
								}
							}*/

							if constexpr (std::is_same_v<T, Pipe>) std::cout << "\n\nPipe's choosing was ";
							else if constexpr (std::is_same_v<T, CompressorStation>) std::cout << "Compressor station's choosing was ";
							if (flag) std::cout << "successful!\n\n";
							else std::cout << "failed\n\n";

							break;
						}

						case 2:
							if constexpr (std::is_same_v<T, Pipe>) {
								bool isRepairing;
								while (true) {
									std::cout << "Choose pipes status (0 - in repairing, 1 - not in repairing): ";
									std::cin >> isRepairing;

									if (checkCinError()) {
										if (std::cin.good()) {
											break;
										}
									}
								}
								for (int i = 0; i <= maxID; i++) {
									if ((isRepairing == unordered_map[i].get_state()) && !(checkElementPresenceInMassive(i, selectedElements))) {
										selectedElements.push_back(i);
										flag = true;
									}
								}
							}

							if constexpr (std::is_same_v<T, CompressorStation>) {
								short int WorkshopsPercentage;
								while (true) {
									std::cout << "\nEnter the percentage of unused workshops: ";
									std::cin >> WorkshopsPercentage;

									if (checkCinError()) {
										if (WorkshopsPercentage < 0) {
											std::cout << "ERROR. The percentage of unused workshops can`t be less than 0\n";
										}
										else if (WorkshopsPercentage > 100) {
											std::cout << "ERROR. The percentage of unused workshops can`t be more than 100\n";
										}
										else {
											break;
										}
									}
								}
								for (int i = 0; i <= maxID; i++) {
									if ((WorkshopsPercentage == unordered_map[i].get_WorkshopsPercentage()) && !(checkElementPresenceInMassive(i, selectedElements))) {
										selectedElements.push_back(i);
										flag = true;
									}
								}
							}

							if constexpr (std::is_same_v<T, Pipe>) std::cout << "\n\nPipe's choosing was ";
							else if constexpr (std::is_same_v<T, CompressorStation>) std::cout << "Compressor station's choosing was ";
							if (flag) std::cout << "successful!\n\n";
							else std::cout << "failed\n\n";

							break;
						}
					}
				}
				break;
			}
			case 2: {
				bool editRemoveChoosingMenuFlag = true;
				while (editRemoveChoosingMenuFlag) {
					action = choosingAction({ "Options:\n\n", "1. Edit", "2. Remove", "0. Back to the menu\n", "Please choose an option : " });
					if (!(action >= 0 && action <= 2))
						clearCin();
					else {
						switch (action) {
						case 0:
							editRemoveChoosingMenuFlag = false;
							break;

						case 1:
							if (editElements(unordered_map, selectedElements)) return true;
							break;
						case 2:
							if (removeElements(unordered_map, selectedElements)) return true;
							break;
						}
					}
				}
				break;
			}
			case 3:
				if (selectedElements.size() > 0) {
					std::cout << "\n\nSelected elements:\n\n";
					if constexpr (std::is_same_v<T, Pipe>) {
						for (int i = 0; i < selectedElements.size(); i++) {
							if (unordered_map[selectedElements[i]].get_name() != "")
								unordered_map[selectedElements[i]].showPipe();
						}
					}

					if constexpr (std::is_same_v<T, CompressorStation>) {
						for (int i = 0; i < selectedElements.size(); i++) {
							if (unordered_map[selectedElements[i]].get_name() != "")
								unordered_map[selectedElements[i]].showCs();
						}
					}
				}
				else {
					std::cout << "\n\nThere are no selected elements\n\n";
				}
				break;
			}
		}

	}
}