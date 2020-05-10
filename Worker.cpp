#include "Worker.h"

Worker::Worker(int work_time, int id, std::string& worker_type)
: work_time(work_time), id(id), worker_type(worker_type) {}

Worker::~Worker() {}
