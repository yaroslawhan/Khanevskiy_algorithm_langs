#pragma once

#include <string>

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