#ifndef GUNSMITH_H
#define GUNSMITH_H
#include "Producer.h"
#include <unordered_map>

class Gunsmith : public Producer {
private:
	int points_producer;
	std::unordered_map<char,int> requirements;
	
public:
	Gunsmith(ProfitPointsCounter& counter, const int id, Inventory& inv);
	virtual void run();
	~Gunsmith();
};

#endif
