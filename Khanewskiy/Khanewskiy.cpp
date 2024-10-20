#include "headers/classes.h"

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef STRING_H
#define STRING_H
#include <string>
#endif

#ifndef FSTREAM_H
#define FSTREAM_H
#include <fstream>
#endif

#ifndef CHECKCINERROR_H
#define CHECKCINERROR_H
#include "headers/checkCinError.h"
#endif

void showMenu() {
	std::cout << "Gas pipeline transport model \n\n";
	std::cout << "Menu: \n";
	std::cout << "1. Add a pipe \n";
	std::cout << "2. Add a compressor station \n";
	std::cout << "3. View all objects \n";
	std::cout << "4. Edit a pipe \n";
	std::cout << "5. Edit a compressor station \n";
	std::cout << "6. Save \n";
	std::cout << "7. Open \n";
	std::cout << "0. Exit \n\n";
	std::cout << "Please select an action :";
}

bool checkCinError() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "ERROR\n";
		return false;
	}
	return true;
}

int main()
{
	Pipe pipe;
	bool pipeExist = false;
	CompressorStation cs;
	bool csExist = false;

	while (1) // Infinity cycle causes a menu
	{
		showMenu();
		unsigned short int action; // Action in menu
		std::cin >> action;

		if (std::cin.good() && action >= 0 && action <= 7) {
			switch (action) {
			case 0:
				return 0;

			case 1:
				if (pipeExist) {
					std::cout << "Pipe is already exist\n\n";
				}
				else {
					pipe.addPipe();
					std::cout << "New pipe added successfully!\n\n";
					pipeExist = true;
				}
				break;

			case 2:
				if (csExist) {
					std::cout << "Compressor station is already exist\n\n";
				}
				else {
					cs.addCs();
					std::cout << "New compressor station added successfully!\n\n";
					csExist = true;
				}
				break;
			case 3:
				if (pipeExist) {
					pipe.showPipes();
				}
				else {
					std::cout << "Pipe does not exist\n\n";
				}
				if (csExist) {
					cs.showCss();
				}
				else {
					std::cout << "Compressor station does not exist\n\n";
				}
				break;
			case 4:
				if (pipeExist) {
					pipe.editPipe();
					std::cout << "The pipe was successfully edited!\n\n";
				}
				else {
					std::cout << "ERROR. Pipe does not exist\n\n";
				}
				break;
			case 5:
				if (csExist) {
					cs.editCs();
					std::cout << "The compressor station was successfully edited!\n\n";
				}
				else {
					std::cout << "ERROR. Compressor station does not exist\n\n";
				}
				break;
			case 6: {
				std::ofstream ifile;
				ifile.open("data.txt");
				pipe.savePipe(ifile, pipeExist);
				if (pipeExist)
					std::cout << "The pipe was successfully saved!\n\n";
				else
					std::cout << "The pipe does not exist\n\n";

				cs.saveCs(ifile, csExist);
				if (csExist) {
					std::cout << "The compressor station was successfully saved!\n\n";
				}
				else
					std::cout << "The compressor station does not exist\n\n";
				ifile.close();
				break;
			}
			case 7: {
				std::ifstream ofile;
				ofile.open("data.txt");
				pipeExist = pipe.loadPipe(ofile);
				if (pipeExist)
					std::cout << "The pipe was successfully loaded!\n\n";
				else
					std::cout << "Pipe does not exist\n\n";

				csExist = cs.loadCs(ofile);
				if (csExist) {
					std::cout << "The compressor station was successfully loaded!\n\n";
				}
				else
					std::cout << "The compressor station does not exist\n\n";
				ofile.close();
				break;
			}
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n\n";
		}
	}
	return 0;
}