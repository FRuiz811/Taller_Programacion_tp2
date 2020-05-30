#include "Miner.h"

#define IRON 'H'
#define COAL 'C'

Miner::Miner(BlockingQueue& queue,const int id, Inventory& inv) :
 Gatherer(queue,id,inv) {}

void Miner::run() {
	Gatherer::run();
	this->inventory.collector_finish(IRON);
	this->inventory.collector_finish(COAL);
}

Miner::~Miner() {}
