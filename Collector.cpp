#include "Collector.h"
#include <unistd.h>
#include <iostream>

Collector::Collector(BlockingQueue& queue,const int id, std::string& type,
	Inventory& inv) : Worker(50, id, type, inv),queue(queue) {}

void Collector::run() {
	while(this->queue.isOpen() || !this->queue.empty()){
		try{
			char resource = this->queue.pop();
			usleep(work_time);
			this->inventory.add_resource(resource);
		} catch (const std::exception&) {
			break;
		}
	}
}

Collector::~Collector() {}