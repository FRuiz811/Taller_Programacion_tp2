#include "Cook.h"

#define COOK_PROFIT 5
#define WHEAT 'T'
#define COAL 'C'
#define WHEAT_REQUIRED 2
#define COAL_REQUIRED 1

Cook::Cook(ProfitPointsCounter& counter,const int id, Inventory& inv) :
 Producer(counter,id,inv) {
 	this->points_producer = COOK_PROFIT;
 	this->requirements[WHEAT] = WHEAT_REQUIRED;
 	this->requirements[COAL] = COAL_REQUIRED;
 }

void Cook::run() {
	Producer::run(this->points_producer, this->requirements);
}

Cook::~Cook() {}
