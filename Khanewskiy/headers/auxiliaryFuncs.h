#pragma once

#include <string>
#include <vector>

bool checkCinError();
void clearCin();
void showMenu();
short int choosingAction(const std::vector<std::string>& strVector);
bool checkElementPresenceInMassive(const int& elem, const std::vector<int> massive);