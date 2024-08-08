#include <iostream>
#include <string>

using namespace std;
class Stack {
    struct Node {
        string data_;
        Node* next_;
        Node(const string& data = "", Node* next = nullptr) {
            data_ = data;
            next_ = next;
        }
    };

    Node* head;
    int numData;
    const int MAX = 5;

    public:
        Stack() {
            head = nullptr;
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

        void push(const string& data) {
            if(isFull()) {
                cout << "Stack is full!, cannot add anymore items" << endl;
                return;
            }
            Node* newNode = new Node(data);
            if(isEmpty()) {
                head = newNode;
            }
            else {
                newNode->next_ = head;
                head = newNode;
            }
            numData++;
        }
        void pop() {
            if(isEmpty()) {
                cout << "Stack is Empty, cannot pop" << endl;
                return;
            }
            Node *temp = head;
            head = head->next_;
            delete temp;
            numData--;
        }

        string top() {
            if(isEmpty()) {
                cout << "Stack is Empty" << endl;
                return NULL;
            }
            return head->data_;
        }
};



int main() {
    Stack fruitStack;

    // Push 5 fruits
    fruitStack.push("Apples");
    cout << "Pushed Apples" <<endl;
    fruitStack.push("Bananas");
    cout << "Pushed Bananas" <<endl;
    fruitStack.push("Grapes");
    cout << "Pushed Grapes" <<endl;
    fruitStack.push("Berries");
    cout << "Pushed Berries" <<endl;
    fruitStack.push("Oranges");
    cout << "Pushed Oranges" <<endl;

    // Display Top pointer data
    cout << "Top pointer data: " << fruitStack.top() << endl;

    // Pop two fruits
    fruitStack.pop();
    cout << "Top pointer data after Pop: " << fruitStack.top() << endl;
    fruitStack.pop();
    cout << "Top pointer data after Pop: " << fruitStack.top() << endl;

    // Check if the Stack is empty
    cout << "Stack is " << (fruitStack.isEmpty() ? "Empty" : "Not Empty") << endl;

    // Check if the Stack is full
    cout << "Stack is " << (fruitStack.isFull() ? "Full" : "Not Full") << endl;

    return 0;
}

