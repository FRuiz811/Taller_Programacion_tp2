#include "Farmer.h"

#define WHEAT 'T'

Farmer::Farmer(BlockingQueue& queue,const int id, Inventory& inv) :
 Collector(queue,id,inv) {}

void Farmer::run() {
	Collector::run();
	this->inventory.collector_finish(WHEAT);
}

Farmer::~Farmer() {}
