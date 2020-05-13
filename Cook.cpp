#include "Cook.h"

#define COOK_PROFIT 5
#define WHEAT 'T'
#define CARBONO 'C'
#define WHEAT_REQUIRED 2
#define CARBONO_REQUIRED 1

Cook::Cook(ProfitPointsCounter& counter,const int id, Inventory& inv) :
 Producer(counter,id,inv) {
 	this->points_producer = COOK_PROFIT;
 	this->requirements[WHEAT] = WHEAT_REQUIRED;
 	this->requirements[CARBONO] = CARBONO_REQUIRED;
 }

void Cook::run() {
	Producer::run(this->points_producer, this->requirements);
}

Cook::~Cook() {}
