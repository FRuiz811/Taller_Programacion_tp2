#ifndef PRODUCER_H
#define PRODUCER_H
#include "Worker.h"
#include "ProfitPointsCounter.h"
#include <unordered_map>

//La clase Producer tiene asignado un contador de puntos de beneficios
//en el cual va a ir sumando los puntos que genera luego de procesar los 
//recursos que obtuvo del inventario. 
class Producer : public Worker {
private:
	ProfitPointsCounter& counter;

public:
	Producer(ProfitPointsCounter& counter, const int id, Inventory& inv);

	//Mientras el inventario del Town esté abierto  y cuente con  los items,
	//que necesite para trabajar, los irá sacando para procesarlos y agregar
	//esos puntos al contador.
	virtual void run(const int points, 
					 const std::unordered_map<char,int> &request);

	virtual ~Producer();

	Producer(Producer &&other) = delete;
    Producer& operator=(Producer&& other) = delete;
    Producer(const Producer&) = delete;
    Producer &operator=(const Producer&) = delete;
};

#endif
