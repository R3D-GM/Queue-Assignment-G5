#include <iostream>
#include "Queue.h"
using namespace std;

// Constructor
Queue::Queue() {
    front = -1;
    rear = -1;
    size = 0;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return size == 0;
}

// Check if the queue is full
bool Queue::isFull() {
    return size == MAX_SIZE;
}

// Add an element to the queue
void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue " << value << "." << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = value;
    size++;

    cout << value << " enqueued to the queue." << endl;
}

// Remove and return an element from the queue
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue." << endl;
        return -1;
    }

    int removedValue = arr[front];

    // If there was only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    size--;
    cout << removedValue << " dequeued from the queue." << endl;
    return removedValue;
}

// Display all elements in the queue
void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";
    int count = 0;
    int index = front;

    while (count < size) {
        cout << arr[index] << " ";
        index = (index + 1) % MAX_SIZE;
        count++;
    }

    cout << endl;
}
