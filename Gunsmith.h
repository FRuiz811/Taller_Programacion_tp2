#ifndef GUNSMITH_H
#define GUNSMITH_H
#include "Producer.h"
#include <unordered_map>

class Gunsmith : public Producer {
private:
	int points_producer;
	std::unordered_map<char,int> requirements;
	
public:
	Gunsmith(ProfitPointsCounter& counter, const int id, Inventory& inv);
	
	//Invoca al método run de Producer, indicandole los puntos que genera
	//y los recursos necesarios para poder hacer su trabajo.
	virtual void run();
	
	~Gunsmith();

	Gunsmith(Gunsmith &&other) = delete;
    Gunsmith& operator=(Gunsmith&& other) = delete;
    Gunsmith(const Gunsmith&) = delete;
    Gunsmith &operator=(const Gunsmith&) = delete;
};

#endif
