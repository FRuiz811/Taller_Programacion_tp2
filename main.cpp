#include "Town.h"
#include "ResourceMap.h"
#include <iostream>


int main(int argc, char *argv[]) {
    if (argc != 3) 
        return 1;
    
    std::string workers_cfg = argv[1];
    std::string map = argv[2];

    //Se lee el archivo de trabajadores y se llaman a las "factory" 
    //de estos asi se crean los hilos.
    Town town(workers_cfg,map);
    town.generate_workers();
    town.process_resources();
    // town.bell();

    return 0;
}