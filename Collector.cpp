#include "Collector.h"
#include <unistd.h>
#include <iostream>

Collector::Collector(BlockingQueue& queue,const int id, std::string& type)
	: Worker(50,id,type),queue(queue) {
	}

void Collector::run() {
	while(this->queue.isOpen() || !this->queue.empty()){
		try{
			char resource = this->queue.pop();
			usleep(work_time);
			std::cout << "Se agrego a INN " << resource << "\n";
		} catch (const std::exception&) {
			break;
		}
	}
}

Collector::~Collector() {}