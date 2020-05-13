#include "Carpenter.h"

#define CARPENTER_PROFIT 2
#define WOOD 'M'
#define WOOD_REQUIRED 3
#define IRON 'H'
#define IRON_REQUIRED 1

Carpenter::Carpenter(ProfitPointsCounter& counter,const int id, Inventory& inv) :
 Producer(counter,id,inv) {
 	this->points_producer = CARPENTER_PROFIT;
 	this->requirements[WOOD] = WOOD_REQUIRED;
 	this->requirements[IRON] = IRON_REQUIRED;
}

void Carpenter::run() {
	Producer::run(this->points_producer, this->requirements);
}

Carpenter::~Carpenter() {}
