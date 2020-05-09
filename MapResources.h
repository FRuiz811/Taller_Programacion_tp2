#ifndef MAPRESOURCES_H
#define MAPRESOURCES_H
#include <string>
#include <fstream>

class MapResources {

private:
	std::string name; 
	std::ifstream file;

public:
	MapResources();

	explicit MapResources(std::string nameFile); 

	MapResources(const MapResources& other) = delete;

 	void process_resources();

	~MapResources();
};

#endif
