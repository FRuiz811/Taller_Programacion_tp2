#ifndef WOODCUTTER_H
#define WOODCUTTER_H
#include "Collector.h"

class WoodCutter : public Collector {
public:
	WoodCutter(BlockingQueue& queue, const int id, Inventory& inv);

	virtual void run();
	
	~WoodCutter();
};

#endif
