#include<iostream>
#include<string>
using namespace std;
struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};
template<class T>
class myqueue {
protected:
    T* arr;
    int size;
    int front, rear;

public:
    myqueue(int s) : size(s), front(-1), rear(-1) {
        arr = new T[size];
    }

    bool isfull() {
        return ((rear + 1) % size == front);
    }

    bool isempty() {
        return (front == -1);
    }

    void enqueue(T val) {
        if (isfull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isempty()) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    bool timeToDeliver(int currentTime) {
        if (isempty()) return false;
        T& pkg = arr[front];
        return currentTime >= pkg.startTime && currentTime <= pkg.endTime;
    }

    void dequeue(int currentTime) {
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (timeToDeliver(currentTime)) {
            cout << "Delivered Package ID: " << arr[front].id << endl;
        }
        else {
            cout << "Package ID " << arr[front].id << " expired and skipped.\n";
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Packages in Queue:\n";
        int i = front;
        do {
            cout << "ID: " << arr[i].id << ", Address: " << arr[i].address
                << ", Start: " << arr[i].startTime
                << ", End: " << arr[i].endTime << endl;
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }

    ~myqueue() {
        delete[] arr;
    }
};
int main() {
    int queueSize;
    cout << "Enter queue size: ";
    cin >> queueSize;

    myqueue<Package> q(queueSize);
    int currentTime = 0;

    while (true) {
        cout << "\nCurrent Time: " << currentTime << endl;
        cout << "1. Enqueue Package\n2. Dequeue (Process Delivery)\n3. Display Packages\n4. Increment Time\n5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Package p;
            cout << "Enter Package ID: ";
            cin >> p.id;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, p.address);
            cout << "Enter Start Time: ";
            cin >> p.startTime;
            cout << "Enter End Time: ";
            cin >> p.endTime;
            q.enqueue(p);
        }
        else if (choice == 2) {
            q.dequeue(currentTime);
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            currentTime++;
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
    system("pause");
}
