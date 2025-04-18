#include <iostream>
using namespace std;

template<typename T>
class QueueUsingStacks {
private:
    int size;
    T* s1;
    T* s2;
    int top1;
    int top2;

public:
    QueueUsingStacks(int sz) {
        size = sz;
        s1 = new T[size];
        s2 = new T[size];
        top1 = -1; // s1 empty
        top2 = -1; // s2 empty
    }

    ~QueueUsingStacks() {
        delete[] s1;
        delete[] s2;
    }

    bool isFull() {
        return top1 == size - 1;
    }

    bool isEmpty() {
        return top1 == -1 && top2 == -1;
    }

    void pushS1(T val) {
        if (top1 < size - 1) {
            s1[++top1] = val;
        }
        else {
            cout << "Queue overflow! Cannot enqueue " << val << endl;
        }
    }

    T popS1() {
        if (top1 >= 0) {
            return s1[top1--];
        }
        return T(); // return default value if empty
    }

    void pushS2(T val) {
        if (top2 < size - 1) {
            s2[++top2] = val;
        }
        else {
            cout << "Queue overflow on s2!" << endl;
        }
    }

    T popS2() {
        if (top2 >= 0) {
            return s2[top2--];
        }
        return T();
    }

    void enqueue() {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        T val;
        cout << "Enter value to enqueue: ";
        cin >> val;
        pushS1(val);
        cout << val << " enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        if (top2 == -1) {
            // Transfer all elements from s1 to s2
            while (top1 != -1) {
                T val = popS1();
                pushS2(val);
            }
        }
        T val = popS2();
        cout << val << " dequeued." << endl;
    }

    void front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (top2 == -1) {
            while (top1 != -1) {
                T val = popS1();
                pushS2(val);
            }
        }
        cout << "Front element is: " << s2[top2] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";

        // Print s2 from top to bottom (front of queue)
        for (int i = top2; i >= 0; i--) {
            cout << s2[i] << " ";
        }

        // Print s1 from bottom to top (rear of queue)
        for (int i = 0; i <= top1; i++) {
            cout << s1[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    QueueUsingStacks<int> q(size);

    int option;
    do {
        cout << "\nOptions:\n1. Display\n2. Enqueue\n3. Dequeue\n4. Front\n5. Exit\nChoose: ";
        cin >> option;

        switch (option) {
        case 1:
            q.display();
            break;
        case 2:
            q.enqueue();
            break;
        case 3:
            q.dequeue();
            break;
        case 4:
            q.front();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (option != 5);

    return 0;
}
