#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Worker.h"
#include "BlockingQueue.h"

class Town {

private:
	std::ifstream fileWorkers;
	std::ifstream fileMap;
	std::map<std::string, int> data;
	std::vector<Worker*> workers;
	BlockingQueue food_warehouse;
	BlockingQueue wood_warehouse;
	BlockingQueue carbon_and_iron_warehouse;
	void run();
	void close_queues();

public:

	explicit Town(const std::string& nameWorkers, const std::string& nameMap); 

	Town(const Town& other) = delete;

 	void generate_workers();
 	void process_resources();
 	void bell();

	~Town();
};

#endif
