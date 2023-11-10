#include "Queue.h"


void Queue::add(int val) {
    q.push(val);
}

int Queue::remove() {
    if (!q.empty()) {
        int frontElement = q.front();
        q.pop();
        return frontElement;
    }
    return -1;
}

int Queue::front() {
    if (!q.empty()) {
        return q.front();
    }
    return -1;
}

bool Queue::isEmpty() {
    return q.empty();
}

int Queue::size() {
    return q.size();
}

void Queue::display() {
    cout << "The queue is: ";
    queue<int> tempQueue = q;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}

