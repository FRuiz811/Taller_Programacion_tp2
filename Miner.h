#ifndef MINER_H
#define MINER_H
#include "Collector.h"

class Miner : public Collector {
public:
	Miner(BlockingQueue& queue, const int id, Inventory& inv);

	virtual void run();
	
	~Miner();

	Miner(Miner &&other) = delete;
    Miner& operator=(Miner&& other) = delete;
    Miner(const Miner&) = delete;
    Miner &operator=(const Miner&) = delete;
};

#endif
