#include <iostream>
#include <string>
using namespace std;

template <typename T>
class RedBlackTree {
private:
    enum Color { RED, BLACK };

    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        Color color;

        Node(T data_) : data(data_), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
    };

    Node* root;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node* z) {
        while (z != root && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    Node* minimum(Node* x) {
        while (x->left != nullptr)
            x = x->left;
        return x;
    }

    void deleteFixup(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    Node* search(Node* node, T data_) {
        if (node == nullptr || node->data == data_)
            return node;

        if (data_ < node->data)
            return search(node->left, data_);
        return search(node->right, data_);
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << "(" << (node->color == RED ? "Red" : "Black") << ") ";
            inorderTraversal(node->right);
        }
    }

    void printNode(Node* node) {
        cout << "Data found: " << node->data << endl;
        cout << "Node color: " << (node->color == RED ? "Red" : "Black") << endl;
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(T data_) {
        Node* z = new Node(data_);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
        insertFixup(z);
    }

    void remove(T data_) {
        Node* z = search(root, data_);
        if (z == nullptr)
            return;

        Node* y = z;
        Node* x;
        Color y_original_color = y->color;
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK)
            deleteFixup(x);
    }

    void search(T data_) {
        Node* result = search(root, data_);
        if (result) {
            printNode(result);
        } else {
            cout << "Data not found." << endl;
        }
    }

    void inOrderTraversal() {
        inorderTraversal(root);
    }
};

int main() {
    RedBlackTree<string> rbString;
    RedBlackTree<int> rbInt;
    RedBlackTree<double> rbDouble;

    cout << "Red-Black Tree with String Data:" << endl;
    rbString.insert("Milton");
    rbString.insert("Ajax");
    rbString.insert("Clarington");
    rbString.insert("Brock");
    rbString.insert("Oshawa");
    rbString.insert("Pickering");
    rbString.insert("Uxbridge");
    rbString.insert("Whitby");
    rbString.insert("Burlington");
    rbString.insert("Oakville");
    rbString.insert("Brampton");
    rbString.insert("Caledon");
    rbString.insert("Mississauga");
    rbString.insert("Aurora");
    rbString.insert("Georgina");
    rbString.inOrderTraversal();

    cout << "\nRed-Black Tree with Integer Data:" << endl;
    rbInt.insert(95);
    rbInt.insert(301);
    rbInt.insert(501);
    rbInt.insert(801);
    rbInt.insert(90);
    rbInt.insert(70);
    rbInt.insert(80);
    rbInt.insert(25);
    rbInt.insert(67);
    rbInt.insert(89);
    rbInt.insert(111);
    rbInt.inOrderTraversal();

    cout << "\nRed-Black Tree with Double Data:" << endl;
    rbDouble.insert(84.8);
    rbDouble.insert(103.5);
    rbDouble.insert(67.8);
    rbDouble.insert(90.3);
    rbDouble.insert(23.5);
    rbDouble.insert(67.1);
    rbDouble.insert(44.5);
    rbDouble.insert(89.2);
    rbDouble.insert(100.5);
    rbDouble.insert(300.22);
    rbDouble.inOrderTraversal();

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
                rbString.insert(dataString);

                cout << "Enter data to insert for int tree: ";
                cin >> dataInt;
                rbInt.insert(dataInt);

                cout << "Enter data to insert for double tree: ";
                cin >> dataDouble;
                rbDouble.insert(dataDouble);
                break;
            case 2:
                cout << "Enter data to delete for string tree: ";
                cin >> dataString;
                rbString.remove(dataString);

                cout << "Enter data to delete for int tree: ";
                cin >> dataInt;
                rbInt.remove(dataInt);

                cout << "Enter data to delete for double tree: ";
                cin >> dataDouble;
                rbDouble.remove(dataDouble);

                break;
            case 3:
                cout << "Enter data to search for string tree: ";
                cin >> dataString;
                rbString.search(dataString);

                cout << "Enter data to search for int tree: ";
                cin >> dataInt;
                rbInt.search(dataInt);

                cout << "Enter data to search for double tree: ";
                cin >> dataDouble;
                rbDouble.search(dataDouble);

                break;
            case 4:
                cout << "\nString Tree data: " << endl;
                rbString.inOrderTraversal();
                cout << "\nInteger Tree data: " << endl;
                rbInt.inOrderTraversal();
                cout << "\nDouble Tree data: " << endl;
                rbDouble.inOrderTraversal();
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