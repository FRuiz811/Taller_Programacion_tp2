#include "Gunsmith.h"

#define GUNSMITH_PROFIT 3
#define IRON 'H'
#define CARBONO 'C'
#define IRON_REQUIRED 2
#define CARBONO_REQUIRED 2

Gunsmith::Gunsmith(ProfitPointsCounter& counter,const int id, Inventory& inv) :
 Producer(counter,id,inv) {
 	this->points_producer = GUNSMITH_PROFIT;
 	this->requirements[IRON] = IRON_REQUIRED;
 	this->requirements[CARBONO] = CARBONO_REQUIRED;
 }

void Gunsmith::run() {
	Producer::run(this->points_producer, this->requirements);
}

Gunsmith::~Gunsmith() {}
