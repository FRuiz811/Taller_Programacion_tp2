#include "Collector.h"
#include <unistd.h>
#include <iostream>

#define COLLECTOR_WORK_TIME 50

Collector::Collector(BlockingQueue& queue,const int id, Inventory& inv) :
 Worker(COLLECTOR_WORK_TIME, id, inv),queue(queue) {}

void Collector::run() {
	char resource = '\0';
	while (this->queue.is_open() || !this->queue.empty()) {
		resource = this->queue.pop();
		if (resource == '\0') 
			break;
		usleep(this->work_time);
		this->inventory.add_resource(resource);
	}
	return;
}

Collector::~Collector() {}
