#ifndef WORKER_H
#define WORKER_H
#include "Thread.h"
#include <string>

class Worker : public Thread {
protected:
	//Refencia a INN
	const int work_time;
	const int id;
	const std::string worker_type;
public:
	Worker(int work_time, int id, std::string& worker_type);
	virtual ~Worker();
	Worker(Worker &&other) = delete;
    Worker& operator=(Worker&& other) = delete;

    Worker(const Worker&) = delete;
    Worker &operator=(const Worker&) = delete;

};

#endif
