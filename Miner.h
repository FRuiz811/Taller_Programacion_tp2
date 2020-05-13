#ifndef MINER_H
#define MINER_H
#include "Collector.h"

class Miner : public Collector {
public:
	Miner(BlockingQueue& queue, const int id, Inventory& inv);

	virtual void run();
	
	~Miner();
};

#endif
