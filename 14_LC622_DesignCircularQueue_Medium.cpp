#include <vector>

class MyCircularQueue {
private:
    std::vector<int> arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor
    MyCircularQueue(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    // Insert element into queue
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;

        return true;
    }

    // Delete element from queue
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    // Get front element
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == capacity;
    }
};

