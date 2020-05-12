#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H
#include <mutex>
#include <condition_variable>
#include <queue>

class BlockingQueue {
private:
	std::queue<char> blocking_queue;
    std::mutex m;
    std::condition_variable cv;
    bool isClosed = false;
    
public:
	BlockingQueue();
	BlockingQueue(BlockingQueue &&other);
    BlockingQueue& operator=(BlockingQueue&& other);
	
	char pop();
	void push(char value);
	void close();
	bool isOpen() const;
	bool empty() const;

	~BlockingQueue();

	BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue &operator=(const BlockingQueue&) = delete;
};

#endif
