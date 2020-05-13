#ifndef FARMER_H
#define FARMER_H
#include "Collector.h"

class Farmer : public Collector {
public:
	Farmer(BlockingQueue& queue, const int id, Inventory& inv);

	virtual void run();
	
	~Farmer();

	Farmer(Farmer &&other) = delete;
    Farmer& operator=(Farmer&& other) = delete;
    Farmer(const Farmer&) = delete;
    Farmer &operator=(const Farmer&) = delete;
};

#endif
