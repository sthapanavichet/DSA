#include<bits/stdc++.h>
using namespace std;

template <typename T>
class AVL {
    // An AVL tree node
    struct Node {
        T data;
        Node *left;
        Node *right;
        int height;
        Node(T data_) {
            data = data_;
            left = nullptr;
            right = nullptr;
            height = 1; // new node is initially
        }
    };

    Node* root;

    int max(int a, int b) {
        if(a > b) return a;
        return b;
    }

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;

        return y;
    }

    int height(Node *N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int getBalance(Node *N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node* balance(Node* node) {
        if (node == nullptr)
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* insertNode(Node* node, T data_) {
        if (node == nullptr)
            return new Node(data_);

        if (data_ < node->data)
            node->left = insertNode(node->left, data_);
        else if (data_ > node->data)
            node->right = insertNode(node->right, data_);
        else // Equal keys are not allowed in BST
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        return balance(node); // Balance the tree after insertion


    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* node, T data_) {
        if (node == nullptr)
            return node;

        if (data_ < node->data)
            node->left = deleteNode(node->left, data_);
        else if (data_ > node->data)
            node->right = deleteNode(node->right, data_);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        return balance(node); // Balance the tree after insertion
    }

    Node* search(Node* node, T data_) {
        if (node == nullptr || node->data == data_)
            return node;

        if (data_ < node->data)
            return search(node->left, data_);
        return search(node->right, data_);
    }

    void inOrder(Node *node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    AVL() {
        root = nullptr;
    }

    void insert(T data_) {
        root = insertNode(root, data_);
    }

    void deleteData(T data_) {
        root = deleteNode(root, data_);
    }

    void searchData(T data_) {
        Node* result = search(root, data_);
        if (result) {
            cout << "Data found: " << result->data << endl;
            cout << "Node height: " << result->height << endl;
        }
        else
            cout << "Data not found." << endl;
    }

    void inOrderTraversal() {
        inOrder(root);
    }
};

int main() {
    AVL<string> avlString;
    AVL<int> avlInt;
    AVL<double> avlDouble;

    cout << "AVL Tree with String Data:" << endl;
    avlString.insert("Milton");
    avlString.insert("Ajax");
    avlString.insert("Clarington");
    avlString.insert("Brock");
    avlString.insert("Oshawa");
    avlString.insert("Pickering");
    avlString.insert("Uxbridge");
    avlString.insert("Whitby");
    avlString.insert("Burlington");
    avlString.insert("Oakville");
    avlString.insert("Brampton");
    avlString.insert("Caledon");
    avlString.insert("Mississauga");
    avlString.insert("Aurora");
    avlString.insert("Georgina");
    avlString.inOrderTraversal();

    cout << "\nAVL Tree with Integer Data:" << endl;
    avlInt.insert(95);
    avlInt.insert(301);
    avlInt.insert(501);
    avlInt.insert(801);
    avlInt.insert(90);
    avlInt.insert(70);
    avlInt.insert(80);
    avlInt.insert(25);
    avlInt.insert(67);
    avlInt.insert(89);
    avlInt.insert(111);
    avlInt.inOrderTraversal();

    cout << "\nAVL Tree with Double Data:" << endl;
    avlDouble.insert(84.8);
    avlDouble.insert(103.5);
    avlDouble.insert(67.8);
    avlDouble.insert(90.3);
    avlDouble.insert(23.5);
    avlDouble.insert(67.1);
    avlDouble.insert(44.5);
    avlDouble.insert(89.2);
    avlDouble.insert(100.5);
    avlDouble.insert(300.22);
    avlDouble.inOrderTraversal();

    int choice;
    bool repeat = true;
    string dataString;
    int dataInt;
    double dataDouble;

    do {
        cout << "Choose an option:\n";
        cout << "1. Insert data\n";
        cout << "2. Delete data\n";
        cout << "3. Search data\n";
        cout << "4. Print tree data\n";
        cout << "5. Exit\n";
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert for string tree: ";
                cin >> dataString;
                avlString.insert(dataString);

                cout << "Enter data to insert for int tree: ";
                cin >> dataInt;
                avlInt.insert(dataInt);

                cout << "Enter data to insert for double tree: ";
                cin >> dataDouble;
                avlDouble.insert(dataDouble);
                break;
            case 2:
                cout << "Enter data to delete for string tree: ";
                cin >> dataString;
                avlString.deleteData(dataString);

                cout << "Enter data to delete for int tree: ";
                cin >> dataInt;
                avlInt.deleteData(dataInt);

                cout << "Enter data to delete for double tree: ";
                cin >> dataDouble;
                avlDouble.deleteData(dataDouble);

                break;
            case 3:
                cout << "Enter data to search for string tree: ";
                cin >> dataString;
                avlString.searchData(dataString);

                cout << "Enter data to search for int tree: ";
                cin >> dataInt;
                avlInt.searchData(dataInt);

                cout << "Enter data to search for double tree: ";
                cin >> dataDouble;
                avlDouble.searchData(dataDouble);

                break;
            case 4:
                cout << "\nString Tree data: " << endl;
                avlString.inOrderTraversal();
                cout << "\nInteger Tree data: " << endl;
                avlInt.inOrderTraversal();
                cout << "\nDouble Tree data: " << endl;
                avlDouble.inOrderTraversal();
                break;
            case 5:
                repeat = false;
                break;
            default:
                cout << "Invalid option!\n";
        }
    } while (repeat);


    return 0;
}
