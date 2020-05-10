#include "BlockingQueue.h"
#include <iostream>

BlockingQueue::BlockingQueue(){}

char BlockingQueue::pop() {
	std::unique_lock<std::mutex> lock(m);
	while(blocking_queue.empty()){
		cv.wait(lock);
	}
	char value = blocking_queue.front();
	blocking_queue.pop();
	return value;
}

void BlockingQueue::push(char value) {
	std::unique_lock<std::mutex> lock(m);
	blocking_queue.push(value);
	cv.notify_all();
}

void BlockingQueue::close() {
	std::unique_lock<std::mutex> lock(m);
	isClosed = true;
	cv.notify_all();
}

BlockingQueue::~BlockingQueue(){}