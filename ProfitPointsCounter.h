#ifndef PROFITPOINTSCOUNTER_H
#define PROFITPOINTSCOUNTER_H
#include <mutex>

class ProfitPointsCounter {
private:
	int counter;
	std::mutex m;

public:
	ProfitPointsCounter();
	ProfitPointsCounter(ProfitPointsCounter &&other);
  ProfitPointsCounter& operator=(ProfitPointsCounter&& other);

	void print_counter() const;
	void add_points(int points);

  ~ProfitPointsCounter();

	ProfitPointsCounter(const ProfitPointsCounter&) = delete;
  ProfitPointsCounter &operator=(const ProfitPointsCounter&) = delete;
};

#endif
