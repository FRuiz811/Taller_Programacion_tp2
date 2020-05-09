#include "Town.h"
#include <iostream>
#include <map>


Town::Town() {}

Town::Town(std::string nameFile) {
	this->name = nameFile;
	this->file.open(this->name, std::ifstream::in);
  if (!file.is_open())
    throw std::exception();
}

void Town::run() {
	for (auto it = workers.begin(); it != workers.end(); ++it) {
				if (it->first == "Agricultores") {
    	for (int i = 0; i<it->second; i++)
    		//Farmer();
    		std::cout << it->first << "\n";
    } else if (it->first == "Leniadores") {
    	for (int i = 0; i<it->second; i++)
   		//WoodCutterr();
   		std::cout << it->first << "\n";
    } else if (it->first == "Mineros") {
    	for (int i = 0; i<it->second; i++)
   		//Miner();
   		std::cout << it->first << "\n";
    } else if (it->first == "Cocineros") {
    	for (int i = 0; i<it->second; i++)
   		//Cook();
   		std::cout << it->first << "\n";
    } else if (it->first == "Carpinteros") {
    	for (int i = 0; i<it->second; i++)
   		//Carpenter();
   		std::cout << it->first << "\n";
    } else if (it->first == "Armeros") {
    	for (int i = 0; i<it->second; i++)
   			//Armorer();
   			std::cout << it->first << "\n";
    } else {
    	throw std::exception();
  	}
    //Agregar el hilo en un array de hilos para despues poder hacer el join de cada uno.
  }
  return;
}

void Town::generate_workers(){
	std::string line;
	int quantity = 0;
	std::size_t equal;

	while (!file.eof()) {
		getline(file,line);
		equal = line.find('=');
		if (equal == std::string::npos)
			break;
		quantity = stoi(line.substr(equal+1, line.size()));
		std::string worker_type = line.substr(0, equal);
		workers.insert(std::pair<std::string,int>(worker_type,quantity));
	}
	run();

	return;
}

Town::~Town() {
	if (this->file.is_open()) {
		this->file.close();
	}
}
