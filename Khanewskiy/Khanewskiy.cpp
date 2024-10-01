/* TODO
* 1. line 43. Error on reading float numbers like 123.456.789 and 123.2343wewe
*/

#include <iostream>
#include <fstream>
#include <string>

struct Pipe
{
	std::string name;
	float length;
	float diameter;
	bool isRepairing = false;
};

struct CompressorStation
{
	std::string name;
	unsigned short int workshopNum;
	unsigned short int activeWorkshopNum;
	float effectiveness;
};

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

void addPipe(Pipe &pipe) {
	std::cout << "Enter name(mileage) of the pipe: ";
	getline(std::cin >> std::ws, pipe.name);

	while (true) {
		std::cout << "\nEnter pipe length (in meters): ";
		std::cin >> pipe.length;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else if (pipe.length <= 0) {
			system("cls");
			std::cout << "ERROR. Pipe length can`t be less than 0 meters or be equal 0 meters\n";
		}
		else if (pipe.length > 50) {
			system("cls");
			std::cout << "ERROR. Pipe length can`t be more than 50 meters\n";
		}
		else {
			break;
		}
	}

	while (true) {
		std::cout << "\nEnter pipe diameter (in millimeters): ";
		std::cin >> pipe.diameter;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else if (pipe.diameter <= 0) {
			system("cls");
			std::cout << "ERROR. Pipe diameter can`t be less than 0 millimeters or be equal 0 millimeters\n";
		}
		else if (pipe.diameter > 5000) {
			system("cls");
			std::cout << "ERROR. Pipe diameter can`t be more than 5000 millimeters\n";
		}
		else {
			break;
		}
	}

	while (true) {
		std::cout << "\nChoose pipe status (0 - in repairing, 1 - not in repairing): ";
		std::cin >> pipe.isRepairing;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else {
			break;
		}
	}
}

void addCs(CompressorStation& cs) {
	std::cout << "Enter name of the compressor station: ";
	getline(std::cin >> std::ws, cs.name);

	while (true) {
		std::cout << "\nEnter the number of workshops: ";
		std::cin >> cs.workshopNum;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else if (cs.workshopNum <= 0) {
			system("cls");
			std::cout << "ERROR. The number of workshops can`t be less than 0 or be equal 0\n";
		}
		else if (cs.workshopNum > 100) {
			system("cls");
			std::cout << "ERROR. The number of workshops can`t be more than 100\n";
		}
		else {
			break;
		}
	}

	while (true) {
		std::cout << "\nEnter the number of active workshops: ";
		std::cin >> cs.activeWorkshopNum;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else if (cs.activeWorkshopNum < 0) {
			system("cls");
			std::cout << "ERROR. The number of active workshops can`t be less than 0\n";
		}
		else if (cs.activeWorkshopNum > 100) {
			system("cls");
			std::cout << "ERROR. The number of active workshops can`t be more than 100\n";
		}
		else if (cs.activeWorkshopNum > cs.workshopNum) {
			system("cls");
			std::cout << "ERROR. The number of active workshops can`t be more than the number of workshops\n";
		}
		else {
			break;
		}
	}

	while (true) {
		std::cout << "\nEnter the compressor station effectiveness: ";
		std::cin >> cs.effectiveness;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else {
			break;
		}
	}
}

void showPipes(Pipe &pipe) {
	std::cout << "Information about pipes:\n\n";
	std::cout << "Pipe name: " << pipe.name;
	std::cout << "\nPipe length: " << pipe.length;
	std::cout << "\nPipe diameter: " << pipe.diameter;
	std::cout << "\nPipe status: " << ((pipe.isRepairing == true) ? "not in repairing\n\n\n" : "in repairing\n\n\n");
}

void showCss(CompressorStation& cs) {
	std::cout << "Information about compressor stations:\n\n";
	std::cout << "Compressor station name: " << cs.name;
	std::cout << "\nThe number of workshops: " << cs.workshopNum;
	std::cout << "\nThe number of active workshops: " << cs.activeWorkshopNum;
	std::cout << "\nThe compressor station effectiveness: " << cs.effectiveness << "\n\n\n";
}

void editPipe(Pipe& pipe) {
	while (true) {
		std::cout << "Enter new pipe status (0 - in repairing, 1 - not in repairing): ";
		std::cin >> pipe.isRepairing;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else {
			break;
		}
	}
}

void editCs(CompressorStation& cs) {
	while (true) {
		std::cout << "\nEnter new value of active workshops: ";
		std::cin >> cs.activeWorkshopNum;

		if (std::cin.fail()) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR\n";
		}
		else if (cs.activeWorkshopNum < 0) {
			system("cls");
			std::cout << "ERROR. The number of active workshops can`t be less than 0\n";
		}
		else if (cs.activeWorkshopNum > 100) {
			system("cls");
			std::cout << "ERROR. The number of active workshops can`t be more than 100\n";
		}
		else if (cs.activeWorkshopNum > cs.workshopNum) {
			system("cls");
			std::cout << "ERROR. The number of active workshops can`t be more than the number of workshops\n";
		}
		else {
			break;
		}
	}
}

void savePipe(Pipe& pipe, bool pipeExist) {
	std::ofstream out;
	out.open("data.txt");

	if (out.is_open()) {
		if (pipeExist) 
			out << pipe.name << ";" << pipe.length << ";" << pipe.diameter << ";" << pipe.isRepairing << "\n";
		else
			out << "\n";
	}
	out.close();
}

void saveCs(CompressorStation& cs, bool csExist) {
	std::ofstream out;
	out.open("data.txt", std::ios::app);

	if (out.is_open()) {
		if (csExist)
			out << cs.name << ";" << cs.workshopNum << ";" << cs.activeWorkshopNum << ";" << cs.effectiveness << "\n";
		else
			out << "\n";
	}
	out.close();
}

int main()
{
	bool programFlag = true;
	Pipe firstPipe;
	Pipe &pipe = firstPipe;
	bool pipeExist = false;
	CompressorStation firstCs;
	CompressorStation& cs = firstCs;
	bool csExist = false;

	while (programFlag) // Infinity cycle causes a menu
	{
		showMenu();
		unsigned short int action; // Action in menu
		std::cin >> action;

		if (std::cin.good() && action >= 0 && action <= 7) {
			switch (action) {
			case 0:
				programFlag = false;
				break;

			case 1:
				system("cls");
				if (pipeExist) {
					std::cout << "Pipe is already exist\n\n";
				}
				else {
					addPipe(pipe);
					system("cls");
					std::cout << "New pipe added successfully!\n\n";
					pipeExist = true;
				}
				break;

			case 2:
				system("cls");
				if (csExist) {
					std::cout << "Compressor station is already exist\n\n";
				}
				else {
					addCs(cs);
					system("cls");
					std::cout << "New compressor station added successfully!\n\n";
					csExist = true;
				}
				break;
			case 3:
				system("cls");
				if (pipeExist) {
					showPipes(pipe);
				}
				else {
					std::cout << "Pipe does not exist\n\n";
				}
				if (csExist) {
					showCss(cs);
				}
				else {
					std::cout << "Compressor station does not exist\n\n";
				}
				break;
			case 4:
				system("cls");
				if (pipeExist) {
					editPipe(pipe);
					system("cls");
					std::cout << "The pipe was successfully edited!\n\n";
				}
				else {
					std::cout << "ERROR. Pipe does not exist\n\n";
				}
				break;
			case 5:
				system("cls");
				if (csExist) {
					editCs(cs);
					system("cls");
					std::cout << "The compressor station was successfully edited!\n\n";
				}
				else {
					std::cout << "ERROR. Compressor station does not exist\n\n";
				}
				break;
			case 6:
				system("cls");
				savePipe(pipe, pipeExist);
				if (pipeExist)
					std::cout << "The pipe was successfully saved!\n\n";
				else
					std::cout << "Pipe does not exist\n\n";

				saveCs(cs, csExist);
				if (csExist) {
					std::cout << "The compressor station was successfully saved!\n\n";
				}
				else
					std::cout << "The compressor station does not exist\n\n";

				break;
			case 7:
				system("cls");
				std::cout << "Coming soon\n\n";
				break;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			system("cls");
			std::cout << "ERROR\n\n";
		}
	}
	return 0;
}