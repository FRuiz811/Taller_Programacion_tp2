#include "BlockingQueue.h"
#include <utility>

BlockingQueue::BlockingQueue(){}

char BlockingQueue::pop() {
	std::unique_lock<std::mutex> lock(m);
	while(blocking_queue.empty()){
		if(isClosed){
			return '\0';
		}
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

bool BlockingQueue::is_open() const {
	return !this->isClosed;
}

bool BlockingQueue::empty() const {
	return this->blocking_queue.empty();
}


BlockingQueue::BlockingQueue(BlockingQueue &&other) {
    this->blocking_queue = std::move(other.blocking_queue);
}

BlockingQueue& BlockingQueue::operator=(BlockingQueue &&other) {
    this->blocking_queue = std::move(other.blocking_queue);
    return *this;
}

BlockingQueue::~BlockingQueue(){}
