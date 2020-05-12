#ifndef INVENTORY_H
#define INVENTORY_H
#include <mutex>
#include <condition_variable>
#include <map>

class Inventory {
private:
	std::map<char,int> resources;
	std::mutex m;
    std::condition_variable cv;

public:
	Inventory();
	Inventory(Inventory &&other);
    Inventory& operator=(Inventory&& other);

	void add_resource(char resource);
	void remove_resource(char resource, int lot);
	void print_resources() const;

    ~Inventory();

	Inventory(const Inventory&) = delete;
    Inventory &operator=(const Inventory&) = delete;
};

#endif
