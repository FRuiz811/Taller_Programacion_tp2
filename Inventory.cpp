#include "Inventory.h"
#include <iostream>
#include <utility>

#define WHEAT 'T'
#define WOOD 'M'
#define IRON 'H'
#define COAL 'C'

Inventory::Inventory(){
	std::unique_lock<std::mutex> lock(m);
	resources[WHEAT] = 0;
	resources[WOOD] = 0;
	resources[IRON] = 0;
	resources[COAL] = 0;
}

Inventory::~Inventory(){}

int Inventory::add_resource(const char resource) {
	std::unique_lock<std::mutex> lock(m);
	auto search_resource = resources.find(resource);
	if (search_resource == resources.end()) 
		return -1;
	resources[resource] += 1;
	this->notified = true;
	cv.notify_all();
	return 0;
}

void Inventory::print_resources() const {
	std::cout << "Recursos restantes:\n";
	auto search_resource = resources.find(WHEAT);
	std::cout << "  - Trigo: " << search_resource->second << "\n";
	search_resource = resources.find(WOOD);
	std::cout << "  - Madera: " << search_resource->second << "\n";
	search_resource = resources.find(COAL);
	std::cout << "  - Carbon: " << search_resource->second << "\n";
	search_resource = resources.find(IRON);
	std::cout << "  - Hierro: " << search_resource->second << "\n";
	std::cout << "\n";
}

int Inventory::remove_resource(const std::unordered_map<char,int>& request) {
	std::unique_lock<std::mutex> lock(m);
	while (!this->notified){
		if (!is_initialize() || !is_open())
			return 1;
		cv.wait(lock);
	}
	for (auto it = request.begin(); it != request.end(); ++it) {
		if (resources.count(it->first) == 0 || 
				resources[it->first] < it->second)
			return -1;
	}
	for (auto it = request.begin(); it != request.end(); ++it) 
		resources[it->first] -= it->second;
	return 0;
}

void Inventory::initialize(const char resource) {
	this->not_initialize = false;
	if (resource == WHEAT) {
		this->farmers_finish = false;
	} else if (resource == WOOD) {
		this->woodcutter_finish = false;
	} else if (resource == COAL || resource == IRON) {
		this->miner_finish = false;
	}
}

bool Inventory::is_initialize() const {
	return !this->not_initialize;
}

bool Inventory::is_open() const {
	return (!this->farmers_finish || !this->woodcutter_finish || 
					!this->miner_finish);
}

void Inventory::collector_finish(const char type) {
	if (type == WHEAT) {
		this->farmers_finish = true;
	} else if (type == WOOD) {
		this->woodcutter_finish = true;
	} else if (type == COAL || type == IRON) {
		this->miner_finish = true;
	}
	cv.notify_all();
}

bool Inventory::is_empty() const {
	int total_resources = 0;
	for (auto it = resources.begin(); it != resources.end(); ++it) 
		total_resources += it->second;
	return total_resources == 0;
}


Inventory::Inventory(Inventory &&other) {
    this->resources = std::move(other.resources);
}

Inventory& Inventory::operator=(Inventory &&other) {
    this->resources = std::move(other.resources);
    return *this;
}
