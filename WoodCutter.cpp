#include "WoodCutter.h"

#define WOOD 'M'

WoodCutter::WoodCutter(BlockingQueue& queue,const int id, Inventory& inv) :
 Gatherer(queue,id,inv) {}

void WoodCutter::run() {
	Gatherer::run();
	this->inventory.collector_finish(WOOD);
}

WoodCutter::~WoodCutter() {}
