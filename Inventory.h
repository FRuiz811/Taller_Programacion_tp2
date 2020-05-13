#ifndef INVENTORY_H
#define INVENTORY_H
#include <mutex>
#include <condition_variable>
#include <unordered_map>

class Inventory {
private:
	std::unordered_map<char,int> resources;
	std::mutex m;
    std::condition_variable cv;
    bool notified = false;

public:
	Inventory();
	Inventory(Inventory &&other);
    Inventory& operator=(Inventory&& other);

	int add_resource(const char resource);
	int remove_resource(const std::unordered_map<char,int> request);
	void print_resources() const;

    ~Inventory();

	Inventory(const Inventory&) = delete;
    Inventory &operator=(const Inventory&) = delete;
};

#endif
