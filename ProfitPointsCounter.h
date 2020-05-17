#ifndef PROFITPOINTSCOUNTER_H
#define PROFITPOINTSCOUNTER_H
#include <mutex>

//La clase ProfitPointsCounter es la encargada de acumular los puntos de 
//beneficios generados por el Town que lo contenga. Cada vez que alguien
//quiera sumar puntos debe haber adquirido el mutex, esto permitirà que
//no se pierdan escrituras.
class ProfitPointsCounter {
private:
	int counter;
	std::mutex m;

public:
	//Constructores para la clase ProfitPointsCounter, se permite el constructor
	//por movimiento, no asi por copia dado que no nos interesa que el 
	//counter sea copiado ya que es único por Town.
	ProfitPointsCounter();
	ProfitPointsCounter(ProfitPointsCounter &&other);
  ProfitPointsCounter& operator=(ProfitPointsCounter&& other);

	void print_counter() const;

	void add_points(const int points);

  ~ProfitPointsCounter();

	ProfitPointsCounter(const ProfitPointsCounter&) = delete;
  ProfitPointsCounter &operator=(const ProfitPointsCounter&) = delete;
};

#endif
