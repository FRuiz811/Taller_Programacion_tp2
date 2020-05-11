#ifndef PROFITPOINTSCOUNTER_H
#define PROFITPOINTSCOUNTER_H
#include <mutex>

class ProfitPointsCounter {
private:
	int counter;
	std::mutex m;

public:
	ProfitPointsCounter();
	~ProfitPointsCounter();
	void print_counter();
	void add_points(int points);
	ProfitPointsCounter(ProfitPointsCounter &&other);
  ProfitPointsCounter& operator=(ProfitPointsCounter&& other);

	ProfitPointsCounter(const ProfitPointsCounter&) = delete;
  ProfitPointsCounter &operator=(const ProfitPointsCounter&) = delete;

};

#endif
