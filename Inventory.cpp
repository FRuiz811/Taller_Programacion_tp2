#include "Inventory.h"
#include <iostream>

#define WHEAT 'T'
#define WOOD 'M'
#define IRON 'H'
#define CARBONO 'C'

Inventory::Inventory(){
	std::unique_lock<std::mutex> lock(m);
	resources[WHEAT] = 0;
	resources[WOOD] = 0;
	resources[IRON] = 0;
	resources[CARBONO] = 0;
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
	std::cout << "Recursos Restantes:\n";
	auto search_resource = resources.find(WHEAT);
	std::cout << "  - Trigo: " << search_resource->second << "\n";
	search_resource = resources.find(WOOD);
	std::cout << "  - Madera: " << search_resource->second << "\n";
	search_resource = resources.find(CARBONO);
	std::cout << "  - Carbón: " << search_resource->second << "\n";
	search_resource = resources.find(IRON);
	std::cout << "  - Hierro: " << search_resource->second << "\n";
	std::cout << "\n";
	return;
}

int Inventory::remove_resource(const std::unordered_map<char,int>& request) {
	std::unique_lock<std::mutex> lock(m);
	while (!this->notified){
		cv.wait(lock);
	}
	for (auto it = request.begin(); it != request.end(); ++it) {
		if (resources.count(it->first) == 0 || 
				resources[it->first] < it->second)
			return -1;
	}
	for (auto it = request.begin(); it != request.end(); ++it) 
			resources[it->first] -= it->second;
	this->notified = false;
	return 0;
}

bool Inventory::isOpen() const {
	return (!this->farmers_finish || !this->woodcutter_finish || 
					!this->miner_finish);
}

void Inventory::collector_finish(const char type) {
	if (type == WHEAT) {
		this->farmers_finish = true;
	} else if (type == WOOD) {
		this->woodcutter_finish = true;
	} else if (type == CARBONO || type == IRON) {
		this->miner_finish = true;
	}
	return;
}


Inventory::Inventory(Inventory &&other) {
    this->resources = std::move(other.resources);
}

Inventory& Inventory::operator=(Inventory &&other) {
    this->resources = std::move(other.resources);
    return *this;
}
