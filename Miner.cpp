#include "Miner.h"

Miner::Miner(BlockingQueue& queue,const int id, Inventory& inv) :
 Collector(queue,id,inv) {}

void Miner::run() {
	Collector::run();
}

Miner::~Miner() {}
