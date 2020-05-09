#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <fstream>
#include <map>

class Town {

private:
	std::string name; 
	std::ifstream file;
	std::map<std::string, int> workers;

	void run();

public:
	Town();

	explicit Town(std::string nameFile); 

	Town(const Town& other) = delete;

 	void generate_workers();

	~Town();
};

#endif
