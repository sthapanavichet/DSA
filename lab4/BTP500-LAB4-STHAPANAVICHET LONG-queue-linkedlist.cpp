#include <string>
#include <iostream>
using namespace std;
class Queue {
    struct Node {
        string data_;
        Node* next_;
        Node(const string& data = "", Node* next = nullptr) {
            data_ = data;
            next_ = next;
        }
    };

    Node* head;
    Node* tail;
    int numData;
    const int MAX = 5;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        numData = 0;
    }
    bool isEmpty() {
        if(numData == 0) return true;
        return false;
    }
    bool isFull() {
        if(numData == MAX) return true;
        return false;
    }

    void enqueue(const string& data) {
        if(isFull()) {
            cout << "Queue is full!, cannot add anymore items" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if(isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next_ = head;
            head = newNode;
        }
        numData++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty, cannot pop" << endl;
            return;
        }
        Node* temp = head;
        while(temp != tail and temp->next_ != tail)
            temp = temp->next_;
        delete tail;
        tail = temp;
        tail->next_ = nullptr;
        numData--;
    }

    string front() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        return tail->data_;
    }
};

int main() {
    Queue fruitQueue;

    // Enqueue 5 fruit
    fruitQueue.enqueue("Apples");
    cout << "Enqueued Apples" <<endl;
    fruitQueue.enqueue("Bananas");
    cout << "Enqueued Bananas" <<endl;
    fruitQueue.enqueue("Grapes");
    cout << "Enqueued Grapes" <<endl;
    fruitQueue.enqueue("Berries");
    cout << "Enqueued Berries" <<endl;
    fruitQueue.enqueue("Oranges");
    cout << "Enqueued Oranges" <<endl;

    // Display front pointer data
    cout << "Front pointer data: " << fruitQueue.front() << endl;

    // Dequeue two fruits
    fruitQueue.dequeue();
    cout << "Front pointer data after dequeue: " << fruitQueue.front() << endl;
    fruitQueue.dequeue();
    cout << "Front pointer data after dequeue: " << fruitQueue.front() << endl;

    // Check if the queue is empty
    cout << "Queue is " << (fruitQueue.isEmpty() ? "Empty" : "Not Empty") << endl;

    // Check if the queue is full
    cout << "Queue is " << (fruitQueue.isFull() ? "Full" : "Not Full") << endl;

    return 0;
}