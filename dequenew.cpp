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
        rear = -1;
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
            front -= 1;
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
            rear += 1;
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
            front += 1;
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
            rear -= 1;
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

    void displayDeque() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        int i = front;
        cout << "Deque elements: ";
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque dq(capacity);
    int choice, value;

    do {
        cout << "\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Get Front\n6. Get Rear\n7. Display Deque\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            dq.insertFront(value);
            break;
        case 2:
            cout << "Enter value to insert at rear: ";
            cin >> value;
            dq.insertRear(value);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << "Front element: " << dq.getFront() << endl;
            break;
        case 6:
            cout << "Rear element: " << dq.getRear() << endl;
            break;
        case 7:
            dq.displayDeque();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}

