//
// Created by sthap on 2/12/2024.
//
#include <iostream>
#include <string>

using namespace std;

class LinkedList {
    struct Node {
        string key_;
        string value_;
        Node* next_;
        Node(const string& key, const string& value, Node* next = nullptr) {
            key_ = key;
            value_ = value;
            next_ = next;
        }
    };
    
    Node* head;
    Node* tail;
    int numData;

    public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        numData = 0;
    }
    bool isEmpty() {
        if(numData == 0) return true;
        return false;
    }

    void append(const string& key, const string& value) {
        Node* newNode = new Node(key, value);
        if(isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            Node* current = head;
            while (current != nullptr && current->key_ != key) {
                current = current->next_;
            }
            if (current != nullptr) current->value_ = value;
            else {
                tail->next_ = newNode;
                tail = newNode;
            }
        }
        numData++;
    }

    void update(const string& key, const string& newKey) {
        Node* current = head;
        while (current != nullptr && current->key_ != key) {
            current = current->next_;
        }
        if (current != nullptr) {
            current->key_ = newKey;
            return;
        }
        cout << "Key doesnt exist" << endl;
    }

    void remove(const string& key) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->key_ != key) {
            prev = current;
            current = current->next_;
        }
        if (current != nullptr) {
            if (prev == nullptr) {
                head = current->next_;
            }
            else {
                prev->next_ = current->next_;
            }
            delete current;
        }
    }

    string find(const string& key) {
        Node* current = head;
        while (current != nullptr && current->key_ != key) {
            current = current->next_;
        }
        if (current != nullptr) {
            return current->value_;
        }
        cout << "Key doesnt exist" << endl;
        return "";
    }

    void display() {
        Node* current = head;
        while(current != nullptr) {
            cout << current->key_ << ": " << current->value_ << endl;
            current = current->next_;
        }
    }

    ~LinkedList() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next_;
            delete temp;
            temp = nullptr;
        }
    }
};


class HashTable {
    static const int SIZE = 10;
    LinkedList* table[SIZE];

    int hash(const string& key) {
        int string_value = 0;
        for(int i = 0; i < key.size(); i++) string_value += key[i];
        return string_value % SIZE;
    }

    public:
    HashTable() {
        for(int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }
    ~HashTable() {
        for(int i = 0; i < SIZE; i++) {
            delete table[i];
            table[i] = nullptr;
        }
    }

    void insert(const string& key, const string& value) {
        int hashIndex = hash(key);
        if(table[hashIndex] == nullptr) {
            table[hashIndex] = new LinkedList();
        }
        table[hashIndex]->append(key, value);
    }

    void update(const string& key, const string& newKey) {
        int hashIndex = hash(key);
        if(table[hashIndex] == nullptr) {
            cout << "Key doesnt exist" << endl;
            return;
        }
        table[hashIndex]->update(key, newKey);
    }

    void remove(const string& key) {
        int hashIndex = hash(key);
        if(table[hashIndex] == nullptr) {
            cout << "Key doesnt exist" << endl;
            return;
        }
        table[hashIndex]->remove(key);
    }

    string find(const string& key) {
        int hashIndex = hash(key);
        if(table[hashIndex] == nullptr) {
            cout << "Key doesnt exist" << endl;
        }
        return table[hashIndex]->find(key);
    }

    void enumerate() {
        for(int i = 0; i < SIZE; i++) {
            cout << "Table " << i+1 << endl;
            if(table[i] != nullptr) table[i]->display();
        }
    }

};

int main() {
    HashTable myHashTable;
    myHashTable.enumerate();
    cout << endl << endl;
    
    myHashTable.insert("Rob Minkoff", "Director");
    myHashTable.insert("Bill Condon", "Director");
    myHashTable.insert("Josh Cooley", "Director");
    myHashTable.insert("Brad Bird", "Director");
    myHashTable.insert("Lake Bell", "Director");

    myHashTable.insert("The Lion King", "Movie Title");
    myHashTable.insert("Beauty and the Beast", "Movie Title");
    myHashTable.insert("Toy Story 4", "Movie Title");
    myHashTable.insert("Mission Impossible", "Movie Title");
    myHashTable.insert("The Secret Life of Pets", "Movie Title");

    myHashTable.insert("2019", "Released Year");
    myHashTable.insert("2017", "Released Year");
    myHashTable.insert("2019", "Released Year");
    myHashTable.insert("2018", "Released Year");
    myHashTable.insert("2016", "Released Year");

    myHashTable.insert("3.50", "Score");
    myHashTable.insert("4.20", "Score");
    myHashTable.insert("4.50", "Score");
    myHashTable.insert("5.00", "Score");
    myHashTable.insert("3.90", "Score");

    myHashTable.enumerate();
    cout << endl << endl;

    myHashTable.remove("The Secret Life of Pets");
    myHashTable.remove("3.90");
    myHashTable.remove("2016");
    myHashTable.remove("Lake Bell");

    myHashTable.enumerate();
    cout << endl << endl;

    myHashTable.update("Toy Story 4", "Toy Story 3");
    myHashTable.update("2019", "2010");
    myHashTable.update("Josh Cooley", "Lee Unkrich");
    myHashTable.update("4.50", "5.00");

    myHashTable.enumerate();
    cout << endl << endl;

    cout << "Finding Mission Impossible movie title: " << myHashTable.find("Mission Impossible") << endl;
    cout << "Finding Bill Condon director: " << myHashTable.find("Bill Condon") << endl;
    cout << "Finding 2018 released year: " << myHashTable.find("2018") << endl;
    cout << "Finding 3.5 score: " << myHashTable.find("3.50") << endl;

    return 0;
}


// hash function for strings: https://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-13.html
