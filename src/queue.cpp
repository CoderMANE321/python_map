#include "queue.h"
#include <stdexcept>

void PyQueue::Enqueue(PyValue val) {
    queue.push_back(val);            // FIFO — enqueue at back
}

PyValue PyQueue::Dequeue() {
    if (queue.empty()) {
        throw std::runtime_error("Queue is empty");
    }
    PyValue val = queue.front();
    queue.pop_front();
    return val;
}

PyValue PyQueue::Peek() const {
    if (queue.empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return queue.front();
}

bool PyQueue::isEmpty() const {
    return queue.empty();
}

size_t PyQueue::Size() const {
    return queue.size();
}
