#include<iostream>
using namespace std;

template<class t>
class AbstractQueue {
public:
    virtual void enQueue(t value) = 0;
    virtual t deQueue() = 0;
    virtual t front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename t>
class myQueue : protected AbstractQueue<t> {
    t* arr;
    int Front;
    int Rear;
    int Size;
public:
    myQueue(int insize) : Size(insize), Front(0), Rear(0) {
        arr = new t[Size];
    }

    ~myQueue() {
        delete[] arr;
    }

    void enQueue(t value) override {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[Rear] = value;
        Rear = (Rear + 1) % Size;  // Circular queue logic
    }

    t deQueue() override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return t();
        }
        t value = arr[Front];
        Front = (Front + 1) % Size;
        return value;
    }

    t front() const override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return t();
        }
        return arr[Front];
    }

    bool isEmpty() const override {
        return Front == Rear;
    }

    bool isFull() const override {
        return (Rear + 1) % Size == Front;
    }



    void display() { for (int i = 0; i < 5; i++) { cout << " queue [" << i << " ] " << arr[i] << endl; } }

};

int main() {
    int size=0;
    cout << " enter size ! "<<endl;
    cin >> size;
    myQueue<int> ar(size);
    for (int i = 0; i < 100; i++) {
        int option = 0;

        cout << " enter option " << endl;
        cin >> option;
        int val = 0;
        if (option == 1) {
            cout << " enqueue value" << endl;
            cin >> val;
            ar.enQueue(val);
        }
        if (option == 2) {
            cout << "Dequeueing: " << ar.deQueue() << endl;
        }

        if (option == 3) {
            cout << " displaying " << endl;
            cout << "---------------------------------------- displaying ----------------------------------------" << endl;
            ar.display();
            cout << "---------------------------------------- displaying ----------------------------------------" << endl;

        }
    }
    return 0;
}