// Khanewskiy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Pipe
{
	std::string name;
	double length;
	double diameter;
	bool isRepairing = false;
};

struct CompressorStation
{
	std::string name;
	unsigned short int workshopNum;
	unsigned short int activeWorkshopNum;
	double effectiveness;
};

std::string action; // Action in menu
bool programFlag = true;
Pipe firstPipe;
CompressorStation cs;
std::string temp;

void createMenu() {
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

Pipe addPipe() {
	Pipe pipe;
	std::cout << "Enter name(mileage) of the pipe: ";
	std::cin >> pipe.name;

	while (true) {
		std::cout << "\nEnter pipe length (in meters): ";
		std::cin >> temp;
		std::cout << std::atof(temp.c_str());
		if (std::atof(temp.c_str()) == 0) std::cout << "ERROR";
		else {
			pipe.length = std::atof(temp.c_str());
			break;
		}
	}

	std::cout << "\nEnter pipe diameter (in millimeters): ";
	std::cin >> pipe.diameter;
	std::cout << "\nChoose pipe status (0 - in repairing, 1 - not in repairing): ";
	std::cin >> pipe.isRepairing;
	return pipe;
}

void showPipe(Pipe pipe) {
	std::cout << "Information about pipes:\n\n";
	std::cout << "Pipe name: " << pipe.name;
	std::cout << "\nPipe length: " << pipe.length;
	std::cout << "\nPipe diameter: " << pipe.diameter;
	std::cout << "\nPipe status: " << ((pipe.isRepairing == true) ? "not in repairing\n\n" : "in repairing\n\n");
}

int main()
{
	while (programFlag) // Infinity cycle causes a menu
	{
		createMenu();
		std::cin >> action;

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
