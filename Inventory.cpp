#include "Inventory.h"
#include <iostream>
#include <utility>

Inventory::Inventory(){
	std::unique_lock<std::mutex> lock(m);
	resources.insert(std::pair<char,int>('T',0));
	resources.insert(std::pair<char,int>('M',0));
	resources.insert(std::pair<char,int>('C',0));
	resources.insert(std::pair<char,int>('H',0));
}

Inventory::~Inventory(){}

void Inventory::add_resource(char resource) {
	std::unique_lock<std::mutex> lock(m);
	auto search_resource = resources.find(resource);
	if (search_resource == resources.end()) 
		throw std::exception();
	int amount = search_resource->second;
	resources.erase(search_resource);
	amount++;
	resources.insert(std::pair<char,int>(resource,amount));
	cv.notify_all();
	return;
}

void Inventory::print_resources() const {
	std::cout << "Recursos Restantes:\n";
	auto search_resource = resources.find('T');
	std::cout << "  - Trigo: " << search_resource->second << "\n";
	search_resource = resources.find('M');
	std::cout << "  - Madera: " << search_resource->second << "\n";
	search_resource = resources.find('C');
	std::cout << "  - Carbón: " << search_resource->second << "\n";
	search_resource = resources.find('H');
	std::cout << "  - Hierro: " << search_resource->second << "\n";
	std::cout << "\n";
	return;
}

void Inventory::remove_resource(char resource, int lot) {
	std::unique_lock<std::mutex> lock(m);
	auto search_resource = resources.find(resource);
	if (search_resource == resources.end()) 
		throw std::exception();
	//int amount = search_resource->second;
	resources.erase(search_resource);
	return;
}

Inventory::Inventory(Inventory &&other) {
    this->resources = std::move(other.resources);
}

Inventory& Inventory::operator=(Inventory &&other) {
    this->resources = std::move(other.resources);
    return *this;
}
