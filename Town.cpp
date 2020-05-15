#include "Town.h"
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string> 
#include "Farmer.h"
#include "WoodCutter.h"
#include "Miner.h"
#include "Cook.h"
#include "Carpenter.h"
#include "Gunsmith.h"

#define WHEAT 'T'
#define WOOD 'M'
#define IRON 'H'
#define CARBONO 'C'

Town::Town(const std::string& nameWorkers, const std::string& nameMap) :
 food_warehouse(), wood_warehouse(),carbon_and_iron_warehouse(),
  inventory(), points() {
	this->fileWorkers.open(nameWorkers, std::ifstream::in);
  if (!this->fileWorkers.is_open())
    throw std::exception();
  this->fileMap.open(nameMap, std::ifstream::in);
  if (!this->fileMap.is_open())
    throw std::exception();
}

void Town::close_queues() {
    this->food_warehouse.close();
    this->wood_warehouse.close();
    this->carbon_and_iron_warehouse.close();
}

int Town::run(const std::unordered_map<std::string, int>& data) {
  int j = 0;
  std::string type;
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (it->first == "Agricultores") {
    	for (int i = 0; i<it->second; i++) {
        this->workers[j] = new Farmer(this->food_warehouse, j, 
                                      this->inventory);
        this->inventory.initialize(WHEAT);
        j++;
      }
    } else if (it->first == "Leniadores") {
    	for (int i = 0; i<it->second; i++) {
   		 this->workers[j] = new WoodCutter(this->wood_warehouse, j, 
                                         this->inventory);
       this->inventory.initialize(WOOD);
       j++;
      }
    } else if (it->first == "Mineros") {
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = new Miner(this->carbon_and_iron_warehouse, j,
                                     this->inventory);
        this->inventory.initialize(IRON);
        j++;
      }
    } else if (it->first == "Cocineros") {
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = new Cook(this->points, j, this->inventory);
        j++;  		
      }
    } else if (it->first == "Carpinteros") {
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = new Carpenter(this->points, j, this->inventory);
        j++;
      }
    } else if (it->first == "Armeros") {
    	for (int i = 0; i<it->second; i++) {
   			this->workers[j] = new Gunsmith(this->points, j, this->inventory);
        j++;
      }
    } else {
    	return -1;
  	}
  }
  size_t total_workers = this->workers.size();
  for (size_t i = 0; i < total_workers; i++){
    this->workers[i]->start();
  }
  return 0;
}

int Town::generate_workers() {
  std::unordered_map<std::string, int> data;
	std::string line;
	int quantity = 0;
	std::size_t equal;
  int total_workers = 0;

	while (this->fileWorkers.good()) {
		getline(this->fileWorkers,line);
		equal = line.find('=');
		if (equal == std::string::npos)
			break;
		quantity = stoi(line.substr(equal+1, line.size()));
		std::string worker_type = line.substr(0, equal);
		data[worker_type] = quantity;
    total_workers +=quantity;
	}
  std::vector<Worker*> vector(total_workers);
  this->workers = std::move(vector);

	return run(data);
}

void Town::load_queue(char resource) {
  switch (resource) {
    case WHEAT:
      food_warehouse.push(resource);
      break;
    case WOOD:
      wood_warehouse.push(resource);
      break;
    case CARBONO:
      carbon_and_iron_warehouse.push(resource);
      break;
    case IRON:
      carbon_and_iron_warehouse.push(resource);
      break;
  }
  return;
}


int Town::process_resources() {
  char resource = ' ';
  std::string line;
  int i = 0;
  while (!this->fileMap.eof()) { 
    getline(this->fileMap,line);
    while (line[i] != '\0') {
      resource = line[i];
      load_queue(resource);
      i++;
    }
    i = 0;
  }
  close_queues();
  return 0;
}

void Town::bell() {
  for (size_t i = 0; i < workers.size(); i++) {
    workers[i]->join();
    delete workers[i];
  }
}

void Town::show_results() const{
  inventory.print_resources();
  points.print_counter();
}

Town::~Town() {
	if (this->fileWorkers.is_open()) {
		this->fileWorkers.close();
	}
  if (this->fileMap.is_open()) {
    this->fileMap.close();
  }
}
