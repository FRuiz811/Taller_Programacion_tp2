#ifndef FARMER_H
#define FARMER_H
#include "Collector.h"

class Farmer : public Collector {
public:
	Farmer(BlockingQueue& queue, const int id, Inventory& inv);

	virtual void run();
	
	~Farmer();
};

#endif
