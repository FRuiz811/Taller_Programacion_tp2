#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Inventory.h"
#include "Worker.h"
#include "BlockingQueue.h"

class Town {

private:
	std::ifstream fileWorkers;
	std::ifstream fileMap;
	std::vector<Worker*> workers;
	BlockingQueue food_warehouse;
	BlockingQueue wood_warehouse;
	BlockingQueue carbon_and_iron_warehouse;
	Inventory inventory;

	void run(const std::map<std::string, int>& data);
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
