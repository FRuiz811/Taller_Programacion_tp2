#ifndef WORKER_H
#define WORKER_H
#include "Thread.h"
#include "Inventory.h"

//Es una clase abstracta, representa un Worker de cualquier tipo, contiene un id y el tiempo que
//tarda en realizar su trabajo. Además tiene una referencia al inventario
//en el cual debe dejar o retirar los recursos que utiliza. 
class Worker : public Thread {
protected:
	const int work_time;
	const int id;
	Inventory& inventory;

public:
	Worker(int work_time, int id, Inventory& inv);
	
	virtual void run() = 0;
    virtual ~Worker();

    Worker(Worker &&other) = delete;
    Worker& operator=(Worker&& other) = delete;
    Worker(const Worker&) = delete;
    Worker &operator=(const Worker&) = delete;
};

#endif
