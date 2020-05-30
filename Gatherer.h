#ifndef GATHERER_H
#define GATHERER_H
#include "Worker.h"
#include "BlockingQueue.h"

//La clase Gatherer tiene asignada una queue que es de la cual van
//a ir retirando sus recursos para luego colocarlos en el inventario
//correspondiente.
class Gatherer : public Worker {
private:
	BlockingQueue& queue;

public:
	Gatherer(BlockingQueue& queue, const int id, Inventory& inv);

	//Mientras la queue de la cual saca recursos esté abierta o con items,
	//irá sacando de a uno para trabajarlos y luego los agregará en el 
	//inventario.
	virtual void run();

	virtual ~Gatherer();

	Gatherer(Gatherer &&other) = delete;
    Gatherer& operator=(Gatherer&& other) = delete;
    Gatherer(const Gatherer&) = delete;
    Gatherer &operator=(const Gatherer&) = delete;
};

#endif
