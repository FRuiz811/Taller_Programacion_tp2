#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Worker.h"
#include "BlockingQueue.h"

class Collector : public Worker {
private:
	BlockingQueue& queue;

public:
	Collector(BlockingQueue& queue, const int id, Inventory& inv);

	virtual void run();

	~Collector();

	Collector(Collector &&other) = delete;
    Collector& operator=(Collector&& other) = delete;
    Collector(const Collector&) = delete;
    Collector &operator=(const Collector&) = delete;
};

#endif
