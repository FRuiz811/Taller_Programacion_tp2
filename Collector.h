#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Worker.h"
#include "BlockingQueue.h"

//La clase Collector tiene asignada una queue que es de la cual van
//a ir retirando sus recursos para luego colocarlos en el inventario
//correspondiente.
class Collector : public Worker {
private:
	BlockingQueue& queue;

public:
	Collector(BlockingQueue& queue, const int id, Inventory& inv);

	//Mientras la queue de la cual saca recursos esté abierta o con items,
	//irá sacando de a uno para trabajarlos y luego los agregará en el 
	//inventario.
	virtual void run();

	virtual ~Collector();

	Collector(Collector &&other) = delete;
    Collector& operator=(Collector&& other) = delete;
    Collector(const Collector&) = delete;
    Collector &operator=(const Collector&) = delete;
};

#endif
