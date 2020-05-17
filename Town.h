#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Inventory.h"
#include "Worker.h"
#include "BlockingQueue.h"
#include "ProfitPointsCounter.h"

//La clase Town es la que hace de orquestador. Tiene como función leer los  
//archivos ingresados como parámetros que generan los diferentes tipos de 
//trabajadores y procesan los materiales que hay en el mapa.
class Town {
private:
	std::ifstream fileWorkers;
	std::ifstream fileMap;
	std::vector<Worker*> workers;
	BlockingQueue food_warehouse;
	BlockingQueue wood_warehouse;
	BlockingQueue carbon_and_iron_warehouse;
	Inventory inventory;
	ProfitPointsCounter points;

	//Recibe como parámetro un unordered_map que tiene como clave el tipo de 
	//worker y el valor indica la cantidad que hay que crear para ese tipo.
	//Es la función que se encarga de mandarlos a correr una vez que están
	//todos creados. Es importante notar que cada worker se aloca en memoria
	//dinámica.
	int run(const std::unordered_map<std::string, int>& data);

	void load_queue(char resource);
	
	void close_queues();
	
	int create_workers(std::string type, int amount);

public:
	//Constructor de la clase, si o si requiere de los archivos de trabajadores
	//y del mapa que tiene los recursos.
	explicit Town(const std::string& nameWorkers, const std::string& nameMap);

	void show_results() const;

	//Procesa el archivo de los trabajadores, generandols en la cantidad 
	//indicada y los ejecuta. 
	//Devuelve -1 en caso de que haya algún error de parseo del archivo, 
	//retorna 0 en caso contrario.
 	int generate_workers();

 	//Procesa el mapa, va cargando las diferentes colas bloqueantes según el 
 	//tipo de recurso que sea. Una vez que termina de procesarlo, cierra las
 	//colas bloqueantes para indicar que no va a haber más recursos.
 	//Retorna -1 en caso de error, 0 en caso de éxito.
 	int process_resources();

 	//Se realiza el join de todos workers y se libera su respectiva memoria.
 	void bell();

	~Town();

	Town(const Town& other) = delete;
	Town &operator=(const Town&) = delete;
};

#endif
