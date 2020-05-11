#include "ProfitPointsCounter.h"
#include <iostream>

ProfitPointsCounter::ProfitPointsCounter(){
	this->counter = 0;
}

void ProfitPointsCounter::add_points(int points) {
	std::unique_lock<std::mutex> lock(m);
	this->counter+=points;
}

void ProfitPointsCounter::print_counter(){
	std::cout << "Puntos de Beneficio acumulados: "<< this->counter <<"\n";
	return;
}
ProfitPointsCounter::ProfitPointsCounter(ProfitPointsCounter &&other) {
    this->counter = std::move(other.counter);
}

ProfitPointsCounter& ProfitPointsCounter::operator=
	(ProfitPointsCounter &&other) {
    this->counter = std::move(other.counter);
    return *this;
}

ProfitPointsCounter::~ProfitPointsCounter(){}
