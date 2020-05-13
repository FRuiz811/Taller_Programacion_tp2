#ifndef COOK_H
#define COOK_H
#include "Producer.h"
#include <unordered_map>

class Cook : public Producer {
private:
	int points_producer;
	std::unordered_map<char,int> requirements;
	
public:
	Cook(ProfitPointsCounter& counter, const int id, Inventory& inv);
	virtual void run();
	~Cook();
};

#endif
