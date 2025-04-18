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

    

    void display() { for (int i = 0; i < 5; i++) { cout<< " queue ["<< i << " ] " << arr[i]<<endl; } }

};

int main() {
    myQueue<int> ar(5);  

    ar.enQueue(1);
    ar.enQueue(2);
    ar.enQueue(3);

    cout << "Front element: " << ar.front() << endl;
    cout << "Dequeueing: " << ar.deQueue() << endl;
    cout << " displaying "<<endl;
    cout << "---------------------------------------- displaying ----------------------------------------" << endl;
    ar.display();
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Front element: " << ar.front() << endl;

    return 0;
}
