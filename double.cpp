#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    ~Deque() {
        delete[] arr;
    }


    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at front" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front = front - 1;
        }

        arr[front] = key;
        size++;
    }


    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at rear" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }

        arr[rear] = key;
        size++;
    }

 
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow! Cannot delete from front" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front = front + 1;
        }

        size--;
    }


    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow! Cannot delete from rear" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear = rear - 1;
        }

        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }

  
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(5);
    dq.insertRear(10);
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After deletion, rear element: " << dq.getRear() << endl;

    dq.insertFront(15);
    cout << "Front element: " << dq.getFront() << endl;

    dq.deleteFront();
    cout << "After deletion, front element: " << dq.getFront() << endl;

    return 0;
}
