#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Inventory.h"
#include "Worker.h"
#include "BlockingQueue.h"
#include "ProfitPointsCounter.h"

class Town {
private:
	std::ifstream fileWorkers;
	std::ifstream fileMap;
	std::vector<Worker*> workers;
	BlockingQueue food_warehouse;
	BlockingQueue wood_warehouse;
	BlockingQueue carbon_and_iron_warehouse;
	Inventory inventory;
	ProfitPointsCounter points;

	int run(const std::unordered_map<std::string, int>& data);
	int load_queue(char resource);
	void close_queues();

public:
	explicit Town(const std::string& nameWorkers, const std::string& nameMap); 

	void show_results() const;
 	int generate_workers();
 	int process_resources();
 	void bell();

	~Town();

	Town(const Town& other) = delete;
	Town &operator=(const Town&) = delete;
};

#endif
