#ifndef CARPENTER_H
#define CARPENTER_H
#include "Producer.h"
#include <unordered_map>

class Carpenter : public Producer {
private:
	int points_producer;
	std::unordered_map<char,int> requirements;
	
public:
	Carpenter(ProfitPointsCounter& counter, const int id, Inventory& inv);
	virtual void run();
	~Carpenter();

	Carpenter(Carpenter &&other) = delete;
    Carpenter& operator=(Carpenter&& other) = delete;
    Carpenter(const Carpenter&) = delete;
    Carpenter &operator=(const Carpenter&) = delete;
};

#endif
