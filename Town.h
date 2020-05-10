#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Thread.h"
#include "BlockingQueue.h"

class Town {

private:
	std::ifstream fileWorkers;
	std::ifstream fileMap;
	std::map<std::string, int> data;
	std::vector<Thread*> workers;
	BlockingQueue food_warehouse;
	BlockingQueue wood_warehouse;
	BlockingQueue carbon_and_iron_warehouse;
	void run();

public:

	explicit Town(std::string nameWorkers, std::string nameMap); 

	Town(const Town& other) = delete;

 	void generate_workers();
 	void process_resources();
 	void bell();

	~Town();
};

#endif
