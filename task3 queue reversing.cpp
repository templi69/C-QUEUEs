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

    int getCurrentSize() const {
        if (Rear >= Front)
            return Rear - Front;
        return Size - Front + Rear;
    }

    void display() {
        cout << "Queue contents: ";
        if (isEmpty()) {
            cout << "Empty" << endl;
            return;
        }
        int i = Front;
        while (i != Rear) {
            cout << arr[i] << " ";
            i = (i + 1) % Size;
        }
        cout << endl;
    }

    void reverseFirstKElements(int k) {
        if (k <= 0 || k > getCurrentSize()) {
            cout << "Invalid value of k!" << endl;
            return;
        }

        t* temp = new t[k];

        // Step 1: Dequeue first K elements
        for (int i = 0; i < k; i++) {
            temp[i] = this->deQueue();
        }

        // Step 2: Enqueue them in reverse order
        for (int i = k - 1; i >= 0; i--) {
            this->enQueue(temp[i]);
        }

        delete[] temp;

        // Step 3: Move the remaining elements to the back
        int remaining = getCurrentSize() - k;
        for (int i = 0; i < remaining; i++) {
            this->enQueue(this->deQueue());
        }
    }
};

int main() {
    myQueue<int> ar(6); // size 6 because circular queue uses one empty slot

    ar.enQueue(1);
    ar.enQueue(2);
    ar.enQueue(3);
    ar.enQueue(4);
    ar.enQueue(5);

    cout << "Original Queue:" << endl;
    ar.display();

    cout << "\nReversing first 3 elements..." << endl;
    ar.reverseFirstKElements(3);

    cout << "\nQueue after reversing first 3 elements:" << endl;
    ar.display();

    return 0;
}
