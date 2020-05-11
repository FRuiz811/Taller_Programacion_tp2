#include "Town.h"
#include <iostream>
#include <map>
#include "Collector.h"

Town::Town(const std::string& nameWorkers, const std::string& nameMap) 
: food_warehouse(),   wood_warehouse(),carbon_and_iron_warehouse(),
  inventory(), points() {
	this->fileWorkers.open(nameWorkers, std::ifstream::in);
  if (!this->fileWorkers.is_open())
    throw std::exception();
  this->fileMap.open(nameMap, std::ifstream::in);
  if (!this->fileMap.is_open())
    throw std::exception();
}

void Town::close_queues() {
    food_warehouse.close();
    wood_warehouse.close();
    carbon_and_iron_warehouse.close();
}

void Town::run(const std::map<std::string, int>& data) {
  int j = 0;
  std::string type;
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (it->first == "Agricultores") {
      type = "Farmer";
    	for (int i = 0; i<it->second; i++) {
        this->workers[j] = new Collector(food_warehouse, i, type, inventory);
        j++;
      }
    } else if (it->first == "Leniadores") {
      type = "WoodCutterr";
    	for (int i = 0; i<it->second; i++) {
   		 this->workers[j] = new Collector(wood_warehouse, i, type, inventory);
   		 j++;
      }
    } else if (it->first == "Mineros") {
      type = "Miner";
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = new Collector(carbon_and_iron_warehouse, i, type, inventory);
        j++;
      }
    }/* else if (it->first == "Cocineros") {
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = Cook();
        j++;  		
      }
    } else if (it->first == "Carpinteros") {
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = Carpenter();
        j++;
      }
    } else if (it->first == "Armeros") {
    	for (int i = 0; i<it->second; i++) {
   			this->workers[j] = Armorer();
        j++;
      }
    } else {
    	throw std::exception();
  	}*/
  }
  size_t total_workers = this->workers.size();
  for (size_t i = 0; i < total_workers; i++){
    this->workers[i]->start();
  }
  return;
}

void Town::generate_workers() {
  std::map<std::string, int> data;
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
		data.insert(std::pair<std::string,int>(worker_type,quantity));
    total_workers +=quantity;
	}
  std::vector<Worker*> vector(total_workers);
  this->workers = std::move(vector);
	run(data);

	return;
}

void Town::process_resources() {
  char resource = ' ';
  std::string line;
  int i = 0;
  while (!this->fileMap.eof()) { 
    getline(this->fileMap,line);
    while (line[i] != '\0') {
      resource = line[i];
      switch(resource) {
        case 'T':
          food_warehouse.push(resource);
          break;
        case 'M':
          wood_warehouse.push(resource);
          break;
        case 'C':
          carbon_and_iron_warehouse.push(resource);
          break;
        case 'H':
          carbon_and_iron_warehouse.push(resource);
          break;
      }
      i++;
    }
    i = 0;
  }
  close_queues();
}

void Town::bell() {
  for (size_t i = 0; i < workers.size(); i++) {
    workers[i]->join();
    delete workers[i];
  }
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
