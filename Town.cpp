#include "Town.h"
#include <iostream>
#include <map>
#include "Farmer.h"

Town::Town(std::string nameWorkers, std::string nameMap) :food_warehouse(),
  wood_warehouse(),carbon_and_iron_warehouse() {
	this->fileWorkers.open(nameWorkers, std::ifstream::in);
  if (!this->fileWorkers.is_open())
    throw std::exception();
  this->fileMap.open(nameMap, std::ifstream::in);
  if (!this->fileMap.is_open())
    throw std::exception();
}

void Town::run() {
  int j = 0;
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (it->first == "Agricultores") {
    	for (int i = 0; i<it->second; i++) {
        //this->workers[j] = new Farmer();
        j++;
      }
    }/* else if (it->first == "Leniadores") {
    	for (int i = 0; i<it->second; i++) {
   		 this->workers[j] = WoodCutterr();
   		 j++;
      }
    } else if (it->first == "Mineros") {
    	for (int i = 0; i<it->second; i++) {
   		  this->workers[j] = Miner();
        j++;
      }
    } else if (it->first == "Cocineros") {
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
  for (size_t i = 0; i < total_workers; ++i)
    std::cout << "Acá sale un Thread\n";
    //this->workers[i]->start();
  return;
}

void Town::generate_workers() {
	std::string line;
	int quantity = 0;
	std::size_t equal;
  int total_workers = 0;

	while (fileWorkers.good()) {
		getline(fileWorkers,line);
		equal = line.find('=');
		if (equal == std::string::npos)
			break;
		quantity = stoi(line.substr(equal+1, line.size()));
		std::string worker_type = line.substr(0, equal);
		data.insert(std::pair<std::string,int>(worker_type,quantity));
    total_workers +=quantity;
	}
  std::vector<Thread*> vector(total_workers);
  workers = vector;
	run();

	return;
}

void Town::process_resources() {
  char resource = ' ';
  std::string line;
  int i = 0;
  getline(this->fileMap,line);
  while (!this->fileMap.eof()) {
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
    getline(this->fileMap,line);
  }
}

void Town::bell() {
  for (size_t i = 0; i < workers.size(); i++) {
    workers[i]->join();
    delete workers[i];
  }
}

Town::~Town() {
	if (this->fileWorkers.is_open()) {
		this->fileWorkers.close();
	}
  if (this->fileMap.is_open()) {
    this->fileMap.close();
  }
}
