#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class BST {
    struct Node {
        Node* right;
        Node* left;
        T data;
        Node(const T &data_, Node* right_ = nullptr, Node* left_ = nullptr) {
            data = data_;
            right = right_;
            left = left_;
        }
    };
    Node* root;

public:
    BST() {
        root = nullptr;
    }
    BST(T *data, int numData) {
        root = nullptr;
        for(int i = 0; i < numData; i++) {
            insert(data++);
        }
    }
    void insert(T *data) {
        if(!root) {
            root = new Node(*data);
            return;
        }
        Node* curr = root;
//        cout << "insert: ";
        while(true) {
//            cout << curr->data << " ";
            if (*data > curr->data) {
                if(curr->right == nullptr) {
                    curr->right = new Node(*data);
                    break;
                }
                curr = curr->right;
            }
            else {
                if(curr->left == nullptr) {
                    curr->left = new Node(*data);
                    break;
                }
                curr = curr->left;
            }
        }
//        cout << endl;
    }

    void preorderTraversal() {
        if (!root) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        stack<Node*> nodes;
        nodes.push(root);

        cout << "Preorder Traversal: ";
        while (!nodes.empty()) {
            Node* curr = nodes.top();
            nodes.pop();

            std::cout << curr->data << " ";

            if (curr->right != nullptr) {
                nodes.push(curr->right);
//                cout << "curr right: " << curr->right->data << endl;
            }

            if (curr->left != nullptr) {
                nodes.push(curr->left);

//                cout << "curr left: " << curr->left->data << endl;
            }
        }
        cout << endl;
    }
    void inorderTraversal() {
        if (!root) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        stack<Node*> nodes;
        Node* curr = root;
        cout << "Inorder Traversal: ";
        while (!nodes.empty() or curr != nullptr) {
            while(curr != nullptr) {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            std::cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    void postorder(Node* curr) {
        if(curr == nullptr) {
            return;
        }
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }

    void postorderTraversal() {
        if (!root) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

};

int main() {
    int intArr[] = {95,301,501,801,90,70,80,25,67,89,11};
    BST<int> int_bst(intArr, 11);

    string strArr[] = {
            "Milton", "Ajax", "Clarington", "Brock", "Oshawa", "Pickering",
            "Uxbridge", "Whitby", "Burlington", "Oakville", "Brampton",
            "Caledon", "Mississauga", "Aurora", "Georgina"
    };
    BST<string> str_bst(strArr, 15);

    float floatArr[] = {84.8,103.5,67.8,90.3,23.5,67.1,44.5,89.2,100.5,300.2};
    BST<float> decimal_bst(floatArr, 10);

    int choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Preorder Tree Traversal" << endl;
        cout << "2. Inorder Tree Traversal" << endl;
        cout << "3. Postorder Tree Traversal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int_bst.preorderTraversal();
                str_bst.preorderTraversal();
                decimal_bst.preorderTraversal();
                break;
            case 2:
                int_bst.inorderTraversal();
                str_bst.inorderTraversal();
                decimal_bst.inorderTraversal();
                break;
            case 3:
                int_bst.postorderTraversal();
                str_bst.postorderTraversal();
                decimal_bst.postorderTraversal();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
