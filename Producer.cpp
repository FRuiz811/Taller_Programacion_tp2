#include "Producer.h"
#include <unistd.h>
#include <iostream>
#include <unordered_map>

#define PRODUCER_WORK_TIME 60

Producer::Producer(ProfitPointsCounter& counter,const int id, Inventory& inv) 
: Worker(PRODUCER_WORK_TIME, id, inv), counter(counter) {}

void Producer::run(const int points, 
				   const std::unordered_map<char,int> &request){
	while(this->inventory.is_open()) {
		int result = this->inventory.remove_resource(request);
		if (result == 0) {
			usleep(this->work_time);
			this->counter.add_points(points);
		} else if (result == 1) {
			break;
		}
	} 
	return;
}

Producer::~Producer() {}
