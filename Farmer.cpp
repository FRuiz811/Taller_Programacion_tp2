#include "Farmer.h"

Farmer::Farmer(BlockingQueue& queue,const int id, Inventory& inv) :
 Collector(queue,id,inv) {}

void Farmer::run() {
	Collector::run();
}

Farmer::~Farmer() {}
