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
	void saveCs(std::ofstream& out);
	void loadCs(std::ifstream& in);
	void showCs();

	std::string get_name();
	float get_WorkshopsPercentage();
};

#endif  CS_H