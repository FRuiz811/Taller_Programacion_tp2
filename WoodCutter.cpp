#include "WoodCutter.h"

WoodCutter::WoodCutter(BlockingQueue& queue,const int id, Inventory& inv) :
 Collector(queue,id,inv) {}

void WoodCutter::run() {
	Collector::run();
}

WoodCutter::~WoodCutter() {}
