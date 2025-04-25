#include <iostream>
using namespace std;

template<class T>
class myqueue {
protected:
    T* arr;
    int size;
    int rear;
    int front;
public:
    myqueue(int insize) {
        size = insize;
        arr = new T[size];
        rear = -1;
        front = -1;
    }

    bool isfull() {
        return ((rear + 1) % size == front);
    }

    bool isempty() {
        return (front == -1);
    }

    void enqueue(T val) {
        if (isfull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (isempty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue contents: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// Main with Precedence Logic
int main() {
    int size;
    cout << "Enter size for teacher and student queues: ";
    cin >> size;

    myqueue<string> teacherQueue(size);
    myqueue<string> studentQueue(size);

    for (int i = 0; i < 100; i++) {
        int option;
        cout << "\nOptions:\n1. Enqueue\n2. Dequeue (with precedence)\n3. Display Both Queues\n4. Exit\n> ";
        cin >> option;

        if (option == 1) {
            string name, role;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter role (teacher/student): ";
            cin >> role;

            if (role == "teacher") {
                teacherQueue.enqueue(name);
            }
            else if (role == "student") {
                studentQueue.enqueue(name);
            }
            else {
                cout << "Invalid role!" << endl;
            }
        }

        else if (option == 2) {
            cout << "Processing print request...\n";
            if (!teacherQueue.isempty()) {
                teacherQueue.dequeue();
            }
            else if (!studentQueue.isempty()) {
                studentQueue.dequeue();
            }
            else {
                cout << "No print requests in any queue.\n";
            }
        }

        else if (option == 3) {
            cout << "\nTeachers Queue:\n";
            teacherQueue.display();
            cout << "Students Queue:\n";
            studentQueue.display();
        }

        else if (option == 4) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
