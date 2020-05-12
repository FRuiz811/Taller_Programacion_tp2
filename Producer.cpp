#include "Producer.h"
#include <unistd.h>
#include <iostream>

Producer::Producer(ProfitPointsCounter& counter,const int id, Inventory& inv) 
: Worker(60, id, inv), counter(counter) {}

Producer::~Producer() {}
