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
	void savePipe(std::ofstream& out);
	void loadPipe(std::ifstream& in);
	void showPipe();

	std::string get_name();
	bool get_state();
	bool operator==(const Pipe& other) const;
};
#endif  PIPE_H