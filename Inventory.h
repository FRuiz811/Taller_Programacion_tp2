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
    bool not_initialize = true;
    bool farmers_finish = true;
    bool woodcutter_finish = true;
    bool miner_finish = true;

public:
	Inventory();
	Inventory(Inventory &&other);
    Inventory& operator=(Inventory&& other);

	int add_resource(const char resource);
	int remove_resource(const std::unordered_map<char,int>& request);
	void print_resources() const;
	bool is_empty() const;
	void initialize(const char resource);
	bool is_initialize() const;
	bool is_open() const;
	void collector_finish(const char type);

    ~Inventory();

	Inventory(const Inventory&) = delete;
    Inventory &operator=(const Inventory&) = delete;
};

#endif
