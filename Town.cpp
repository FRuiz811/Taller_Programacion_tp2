#include "Town.h"
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string> 
#include "Gatherer.h"
#include "Producer.h"

#define WHEAT 'T'
#define WOOD 'M'
#define IRON 'H'
#define COAL 'C'

Town::Town(const std::string& nameWorkers, const std::string& nameMap) :
 food_warehouse(), wood_warehouse(),coal_and_iron_warehouse(),
  inventory(), points() {
	this->fileWorkers.open(nameWorkers, std::ifstream::in);
  if (!this->fileWorkers.is_open())
    throw std::exception();
  this->fileMap.open(nameMap, std::ifstream::in);
  if (!this->fileMap.is_open())
    throw std::exception();
}

int Town::create_workers(std::string type, int amount) {
  static int j = 0;
  if (type == "Agricultores") {
      for (int i = 0; i < amount; i++) {
        this->workers[j] = new Gatherer(this->food_warehouse, j, 
                                      this->inventory);
        j++;
      }
    } else if (type == "Leniadores") {
      for (int i = 0; i < amount; i++) {
       this->workers[j] = new Gatherer(this->wood_warehouse, j, 
                                         this->inventory);
       j++;
      }
    } else if (type == "Mineros") {
      for (int i = 0; i < amount; i++) {
        this->workers[j] = new Gatherer(this->coal_and_iron_warehouse, j,
                                     this->inventory);
        j++;
      }
    } else {
      for (int i = 0; i < amount; i++) {
        this->workers[j] = Producer::factory(type, this->points,
                                                 j, this->inventory);
        j++;      
      }
    }
    return 0;
}

int Town::run(const std::unordered_map<std::string, int>& data) {
  int result = 0;
	for (auto it = data.begin(); it != data.end(); ++it) {
		result = create_workers(it->first, it->second);
  }
  
  size_t total_workers = this->workers.size();
  for (size_t i = 0; i < total_workers; i++){
    this->workers[i]->start();
  }
  return result;
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
    case COAL:
      coal_and_iron_warehouse.push(resource);
      break;
    case IRON:
      coal_and_iron_warehouse.push(resource);
      break;
  }
}

void Town::close_queues() {
    this->food_warehouse.close();
    this->wood_warehouse.close();
    this->coal_and_iron_warehouse.close();
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
