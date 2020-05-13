#include "Producer.h"
#include <unistd.h>
#include <iostream>

#define PRODUCER_WORK_TIME 60

Producer::Producer(ProfitPointsCounter& counter,const int id, Inventory& inv) 
: Worker(PRODUCER_WORK_TIME, id, inv), counter(counter) {}

void Producer::run(const int points, 
				   const std::unordered_map<char,int> request){
	int result = this->inventory.remove_resource(request);
	if (result == 0) {
		usleep(PRODUCER_WORK_TIME);
		this->counter.add_points(points);
	}
}

Producer::~Producer() {}
