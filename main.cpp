#include "Town.h"
#include "MapResources.h"

int main(int argc, char *argv[]) {
    if (argc != 3) 
        return 1;
    
    std::string workers_cfg = argv[1];
    std::string map = argv[2];
    //Falta crear el CounterPoints (Ver si va dentro de Town o directamente acá)

    //Se lee el archivo de trabajadores y se llaman a las "factory" 
    //de estos asi se crean los hilos.
    Town town(workers_cfg);
    town.generate_workers();
    MapResources map(map);



    return 0;
}