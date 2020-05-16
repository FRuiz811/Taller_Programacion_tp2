#include "WoodCutter.h"

#define WOOD 'M'

WoodCutter::WoodCutter(BlockingQueue& queue,const int id, Inventory& inv) :
 Collector(queue,id,inv) {}

void WoodCutter::run() {
	Collector::run();
	this->inventory.collector_finish(WOOD);
}

WoodCutter::~WoodCutter() {}
