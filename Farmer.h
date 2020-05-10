#ifndef FARMER_H
#define FARMER_H
#include "Thread.h"

class Farmer : public Thread {
private:
	int work_time = 50;
	
public:
	Farmer();
	void run();
	~Farmer();
};

#endif
