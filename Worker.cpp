#include "Worker.h"

Worker::Worker(int work_time, int id, Inventory& inv)
: work_time(work_time), id(id), inventory(inv) {}

Worker::~Worker() {}
