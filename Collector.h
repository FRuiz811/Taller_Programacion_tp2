#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Worker.h"
#include "BlockingQueue.h"

class Collector : public Worker {

private:
	BlockingQueue& queue;

public:
	Collector(BlockingQueue& queue,
		const int id,std::string& type, Inventory& inv);
	void run();
	~Collector();
};

#endif
