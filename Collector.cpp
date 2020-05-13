#include "Collector.h"
#include <unistd.h>
#include <iostream>

#define COLLECTOR_WORK_TIME 50

Collector::Collector(BlockingQueue& queue,const int id, Inventory& inv) :
 Worker(COLLECTOR_WORK_TIME, id, inv),queue(queue) {}

void Collector::run() {
	char resource = '\0';
	while(this->queue.isOpen() || !this->queue.empty()){
			resource = this->queue.pop();
			if (resource == '\0') 
				return;
			usleep(this->work_time);
			this->inventory.add_resource(resource);
	}
	this->inventory.collector_finish(resource);
	return;
}

Collector::~Collector() {}
