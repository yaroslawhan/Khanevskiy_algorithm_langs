#pragma once

#include <string>

#ifndef CS_H
#define CS_H

class CompressorStation
{
private:
	std::string name;
	short int workshopNum;
	short int activeWorkshopNum;
	float effectiveness;
public:
	void addCs();
	void editCs();
	bool saveCs(std::ofstream& out, bool csExist);
	bool loadCs(std::ifstream& in);
	void showCss();
};

#endif  CS_H