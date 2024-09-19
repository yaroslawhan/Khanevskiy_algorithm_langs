/* TODO
* 1. line 43. Error on reading float numbers like 123.456.789 and 123.2343wewe
*/

#include <iostream>
#include <fstream>

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
	std::cin >> pipe.name;

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
	std::cin >> cs.name;

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

void save(Pipe& pipe, bool pipeExist, CompressorStation& cs, bool csExist) {
	std::ofstream out;
	out.open("data.txt");

	if (out.is_open()) {
		if (pipeExist) {
			
		}
		
		if (csExist) {

		}
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
					addPipe(pipe);
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
					addCs(cs);
					system("cls");
					std::cout << "The compressor station was successfully edited!\n\n";
				}
				else {
					std::cout << "ERROR. Compressor station does not exist\n\n";
				}
				break;
			case 6:
				system("cls");
				save(pipe, pipeExist, cs, csExist);
				std::cout << "Information was saved!\n\n";
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


		/*
		if (action == "0") {
			programFlag = false;
		}
		else if (action == "1") {
			system("cls");
			firstPipe = addPipe();
			system("cls");
			std::cout << "New pipe added successfully!\n\n";
		}
		else if (action == "3") {
			system("cls");
			showPipe(firstPipe);
		}
		else {
			system("cls");
			std::cout << "ERROR\n\n";
		}
		*/
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
