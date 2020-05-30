#ifndef WOODCUTTER_H
#define WOODCUTTER_H
#include "Gatherer.h"

class WoodCutter : public Gatherer {
public:
	WoodCutter(BlockingQueue& queue, const int id, Inventory& inv);

	//Llama al run de Gatherer y luego indica que finalizó su trabajo
	//al inventario.
	virtual void run();
	
	~WoodCutter();

	WoodCutter(WoodCutter &&other) = delete;
    WoodCutter& operator=(WoodCutter&& other) = delete;
    WoodCutter(const WoodCutter&) = delete;
    WoodCutter &operator=(const WoodCutter&) = delete;
};

#endif
