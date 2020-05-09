#include "MapResources.h"


MapResources::MapResources(){}

MapResources::MapResources(std::string nameFile) {
	this->name = nameFile;
	this->file.open(this->name, std::ifstream::in);
	  if (!file.is_open())
    	throw std::exception();
}

void MapResources::process_resources() {
	char resource = ' ';
	while (file.get(resource)) {
		switch(resource) {
			case 'T':
			case 'H':
			case 'C':
			case 'M':
			default:
		}
	}
}

MapResources::~MapResources() {
	if (this->file.is_open()) {
		this->file.close();
	}
}
