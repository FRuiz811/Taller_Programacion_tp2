#ifndef FARMER_H
#define FARMER_H
#include "Gatherer.h"

class Farmer : public Gatherer {
public:
	Farmer(BlockingQueue& queue, const int id, Inventory& inv);

	//Llama al run de Gatherer y luego indica que finalizó su trabajo
	//al inventario.
	virtual void run();
	
	~Farmer();

	Farmer(Farmer &&other) = delete;
    Farmer& operator=(Farmer&& other) = delete;
    Farmer(const Farmer&) = delete;
    Farmer &operator=(const Farmer&) = delete;
};

#endif
