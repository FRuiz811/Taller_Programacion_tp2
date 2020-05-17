#ifndef COOK_H
#define COOK_H
#include "Producer.h"
#include <unordered_map>

class Cook : public Producer {
private:
	int points_producer;
	std::unordered_map<char,int> requirements;
	
public:
	Cook(ProfitPointsCounter& counter, const int id, Inventory& inv);

	//Invoca al método run de Producer, indicandole los puntos que genera
	//y los recursos necesarios para poder hacer su trabajo.
	virtual void run();
	
	~Cook();

	Cook(Cook &&other) = delete;
    Cook& operator=(Cook&& other) = delete;
    Cook(const Cook&) = delete;
    Cook &operator=(const Cook&) = delete;
};

#endif
