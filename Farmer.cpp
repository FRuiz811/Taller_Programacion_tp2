#include "Farmer.h"

#define WHEAT 'T'

Farmer::Farmer(BlockingQueue& queue,const int id, Inventory& inv) :
 Gatherer(queue,id,inv) {}

void Farmer::run() {
	Gatherer::run();
	this->inventory.collector_finish(WHEAT);
}

Farmer::~Farmer() {}
