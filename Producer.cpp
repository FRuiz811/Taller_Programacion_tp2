#include "Producer.h"
#include <unistd.h>
#include <iostream>
#include <unordered_map>
#include <string>

#define PRODUCER_WORK_TIME 60000
#define WHEAT 'T'
#define COAL 'C'
#define WOOD 'M'
#define IRON 'H'

Producer::Producer(ProfitPointsCounter& counter,const int id, Inventory& inv) 
: Worker(PRODUCER_WORK_TIME, id, inv), counter(counter) {}

void Producer::create_cook() {
	const int cook_profit = 5;
	const int wheat_required = 2;
	const int coal_required = 1;

	this->points_producer = cook_profit;
 	this->requirements[WHEAT] = wheat_required;
 	this->requirements[COAL] = coal_required;
}

void Producer::create_carpenter() {
	const int carpenter_profit = 2;
	const int wood_required = 3;
	const int iron_required = 1;

	this->points_producer = carpenter_profit;
 	this->requirements[WOOD] = wood_required;
 	this->requirements[IRON] = iron_required;
}

void Producer::create_gunsmith() {
	const int gunsmith_profit = 3;
	const int coal_required = 2;
	const int iron_required = 2;

	this->points_producer = gunsmith_profit;
 	this->requirements[COAL] = coal_required;
 	this->requirements[IRON] = iron_required;
}

Producer* Producer::factory(std::string type,
								ProfitPointsCounter& counter, int id, Inventory& inv) {
	Producer* producer = new Producer(counter, id, inv);
	if (type == "Cocineros") {
		producer->create_cook();
	} else if (type == "Carpinteros") {
		producer->create_carpenter();
	} else if (type == "Armeros") {
		producer->create_gunsmith();
	}

	return producer;
}

void Producer::run(){
	while(this->inventory.is_open()) {
		int result = this->inventory.remove_resource(this->requirements);
		if (result == 0) {
			usleep(this->work_time);
			this->counter.add_points(this->points_producer);
		} else if (result == 1) {
			break;
		}
	}
}


Producer::~Producer() {}
