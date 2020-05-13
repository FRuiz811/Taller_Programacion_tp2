#include "Town.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3) 
        return 1;
    
    const std::string workers_cfg = argv[1];
    const std::string map = argv[2];

    Town town(workers_cfg,map);
    if (town.generate_workers() == -1)
        return 1;
    if (town.process_resources() == -1) 
        return 1;
    town.bell();
    town.show_results();

    return 0;
}
