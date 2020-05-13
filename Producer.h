#ifndef PRODUCER_H
#define PRODUCER_H
#include "Worker.h"
#include "ProfitPointsCounter.h"

class Producer : public Worker {
private:
	ProfitPointsCounter& counter;

public:
	Producer(ProfitPointsCounter& counter, const int id, Inventory& inv);

	virtual void run(const int points, 
					 const std::unordered_map<char,int> &request);

	~Producer();

	Producer(Producer &&other) = delete;
    Producer& operator=(Producer&& other) = delete;
    Producer(const Producer&) = delete;
    Producer &operator=(const Producer&) = delete;
};

#endif
