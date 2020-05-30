#include "Gatherer.h"
#include <unistd.h>
#include <iostream>

#define GATHERER_WORK_TIME 50000

Gatherer::Gatherer(BlockingQueue& queue,const int id, Inventory& inv) :
 Worker(GATHERER_WORK_TIME, id, inv),queue(queue) {}

void Gatherer::run() {
	char resource = '\0';
	while (this->queue.is_open() || !this->queue.empty()) {
		resource = this->queue.pop();
		if (resource == '\0') 
			break;
		usleep(this->work_time);
		this->inventory.add_resource(resource);
	}
}

Gatherer::~Gatherer() {}
