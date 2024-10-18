#ifndef PIPE_H
#define PIPE_H

class Pipe
{
private:
	std::string name;
	float length;
	int diameter;
	bool isRepairing = false;
	bool pipeExist = false;
public:
	void addPipe();
	void editPipe();
	bool savePipe(std::ofstream& out);
	bool loadPipe(std::ifstream& in);
	std::ostream& operator << (std::ostream& out);
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
	bool csExist = false;
public:
	void addCs();
	void editCs();
	bool saveCs(std::ofstream& out);
	bool loadCs(std::ifstream& in);
	std::ostream& operator << (std::ostream& out);
};

#endif  CS_H