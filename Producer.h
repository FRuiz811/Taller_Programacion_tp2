#ifndef PRODUCER_H
#define PRODUCER_H
#include "Worker.h"
#include "ProfitPointsCounter.h"

class Producer : public Worker {
private:
	ProfitPointsCounter& counter;

public:
	Producer(ProfitPointsCounter& counter, const int id, Inventory& inv);
	virtual void run() = 0;
	~Producer();
};

#endif
