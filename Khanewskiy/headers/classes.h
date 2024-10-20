#pragma once

#ifndef STRING_H
#define STRING_H
#include <string>
#endif

#ifndef PIPE_H
#define PIPE_H

class Pipe
{
private:
	std::string name;
	float length;
	int diameter;
	bool isRepairing = false;
public:
	Pipe();
	void addPipe();
	void editPipe();
	bool savePipe(std::ofstream& out, bool pipeExist);
	bool loadPipe(std::ifstream& in);
	void showPipes();
};

#endif  PIPE_H


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