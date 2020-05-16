#include "Miner.h"

#define IRON 'H'

Miner::Miner(BlockingQueue& queue,const int id, Inventory& inv) :
 Collector(queue,id,inv) {}

void Miner::run() {
	Collector::run();
	this->inventory.collector_finish(IRON);
}

Miner::~Miner() {}
