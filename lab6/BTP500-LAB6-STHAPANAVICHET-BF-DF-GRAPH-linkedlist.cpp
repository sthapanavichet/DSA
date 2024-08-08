#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LinkedList {
    struct Node {
        int data_;
        Node *next_;

        Node(const int &data = int{}, Node *next = nullptr) {
            data_ = data;
            next_ = next;
        }
    };
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(const int &data) {
        if(head) {
            Node *newNode = new Node(data, head);
            head = newNode;
        }
        else {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        Node* temp = head;
        if(head == tail) {
            delete temp;
            head = nullptr;
            tail = nullptr;
            return;
        }
        head = head->next_;
        delete temp;
    }

    void push_back(const int &data) {
        Node *newNode = new Node(data);
        if (tail)
            tail->next_ = newNode;
        else
            head = newNode;

        tail = newNode;
    }

    void pop_back() {
        Node *temp = head;
        if(head == tail) {
            delete temp;
            head = nullptr;
            tail = nullptr;
            return;
        }
        while(temp->next_ != tail) temp = temp->next_;
        temp->next_ = nullptr;
        delete tail;
        tail = temp;
    }

    bool search(int n) {
        Node *temp = head;
        while(temp) {
            if(temp->data_ == n) return true;
            temp = temp->next_;
        }
        return false;
    }

    bool empty() {
        return !head;
    }

    int front() {
        if(head) return head->data_;
        else return -1;
    }

    int back() {
        if(tail) return tail->data_;
        else return -1;
    }

    ~LinkedList() {
        Node *temp;
        while (head) {
            temp = head->next_;
            delete head;
            head = temp;
        }
    }

    void printData() {
        Node* temp = head;
        while(temp) {
            std::cout << temp->data_ << " ";
            temp = temp->next_;
        }
        std::cout << std::endl;
    }
    void getData(vector<int> *arr) {
        Node* temp = head;
        while(temp) {
            arr->push_back(temp->data_);
            temp = temp->next_;
        }
    }
};

class Graph {
    int **matrix;
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        matrix = new int*[vertices];
        for(int i = 0; i < vertices; i++) {
            matrix[i] = new int[vertices];
            for (int v2 = 0; v2 < vertices; v2++) {
                matrix[i][v2] = 0;
            }
        }

    }
    void addEdge(const int& v1, const int& v2) {
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices) {
            matrix[v1][v2] = 1;
            matrix[v2][v1] = 1;
        } else {
            cout << "Invalid vertices provided" << v1 << ", " << v2 << endl;
        }
    }

    void BFS(int start, vector<int> *ret) {
        LinkedList queue;
        queue.push_front(start);
        ret->push_back(start);
        while(!queue.empty()) {
            int v1 = queue.back();
            queue.pop_back();
            for(int v2 = 0; v2 < vertices; v2++) {
                if(matrix[v1][v2] == 1 && find(ret->begin(), ret->end(), v2) == ret->end()) {
                    queue.push_front(v2);
                    ret->push_back(v2);
                }
            }

        }
    }

    void DFS(int start, vector<int> *ret) {
        LinkedList stack;
        vector<int> visited;
        stack.push_back(start);
        visited.push_back(start);
        while(!stack.empty()) {
            int v1 = stack.back();
            stack.pop_back();
            ret->push_back(v1);
            for(int v2 = 0; v2 < vertices; v2++) {
                if(matrix[v1][v2] == 1 && find(visited.begin(), visited.end(), v2) == visited.end()) {
                    stack.push_back(v2);
                    visited.push_back(v2);
                }
            }

        }
    }

    void printMatrix() {
        for(int v1 = 0; v1 < vertices; v1++) {
            for(int v2 = 0; v2 < vertices; v2++) {
                cout << matrix[v1][v2];
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    ~Graph() {
        // Deallocate memory for each row
        for (int i = 0; i < vertices; ++i) {
            delete[] matrix[i];
        }
        // Deallocate memory for the array of pointers
        delete[] matrix;
    }


};




int main() {
    string state[57];
    state[0] = "Alabama";
    state[1] = "Alaska";
    state[2] = "Arizona";
    state[3] = "Arkansas";
    state[4] = "California";
    state[5] = "Colorado";
    state[6] = "Connecticut";
    state[7] = "Delaware";
    state[8] = "Florida";
    state[9] = "Georgia";
    state[10] = "Hawaii";
    state[11] = "Idaho";
    state[12] = "Illinois";
    state[13] = "Indiana";
    state[14] = "Iowa";
    state[15] = "Kansas";
    state[16] = "Kentucky";
    state[17] = "Louisiana";
    state[18] = "Maine";
    state[19] = "Maryland";
    state[20] = "Massachusetts";
    state[21] = "Michigan";
    state[22] = "Minnesota";
    state[23] = "Mississippi";
    state[24] = "Missouri";
    state[25] = "Montana";
    state[26] = "Nebraska";
    state[27] = "Nevada";
    state[28] = "New Hampshire";
    state[29] = "New Jersey";
    state[30] = "New Mexico";
    state[31] = "New York";
    state[32] = "North Carolina";
    state[33] = "North Dakota";
    state[34] = "Ohio";
    state[35] = "Oklahoma";
    state[36] = "Oregon";
    state[37] = "Pennsylvania";
    state[38] = "Rhode Island";
    state[39] = "South Carolina";
    state[40] = "South Dakota";
    state[41] = "Tennessee";
    state[42] = "Texas";
    state[43] = "Utah";
    state[44] = "Vermont";
    state[45] = "Virginia";
    state[46] = "Washington";
    state[47] = "West Virginia";
    state[48] = "Wisconsin";
    state[49] = "Wyoming";
    state[50] = "District of Columbia";
    state[51] = "American Samoa";
    state[52] = "Guam";
    state[53] = "Northern Mariana Islands";
    state[54] = "Puerto Rico";
    state[55] = "United States Minor Outlying Islands";
    state[56] = "Virgin Islands";


    Graph states(52);
    states.addEdge(0, 23);  // Mississippi
    states.addEdge(0, 8);   // Florida
    states.addEdge(0, 9);   // Georgia
    states.addEdge(0, 41);  // Tennessee

    // Arizona
    states.addEdge(2, 4);  // California
    states.addEdge(2, 5);  // Colorado
    states.addEdge(2, 29); // New Mexico
    states.addEdge(2, 30); // Nevada
    states.addEdge(2, 43); // Utah

    // Arkansas
    states.addEdge(3, 42);  // Texas
    states.addEdge(3, 23);  // Mississippi
    states.addEdge(3, 24); // Missouri
    states.addEdge(3, 35); // Oklahoma
    states.addEdge(3, 41); // Tennessee
    states.addEdge(3, 17); // Louisiana

    // California
    states.addEdge(4, 2);  // Arizona
    states.addEdge(4, 30); // Nevada
    states.addEdge(4, 36); // Oregon

    // Colorado
    states.addEdge(5, 2);  // Arizona
    states.addEdge(5, 43); // Utah
    states.addEdge(5, 35); // Oklahoma
    states.addEdge(5, 15); // Kansas
    states.addEdge(5, 30); // New Mexico
    states.addEdge(5, 26); // Nebraska
    states.addEdge(5, 49); // Wyoming

    // Connecticut
    states.addEdge(6, 31);  // New York
    states.addEdge(6, 20);  // Massachusetts
    states.addEdge(6, 38);  // Rhode Islands

    // Delaware
    states.addEdge(7, 37); // Pennsylvania
    states.addEdge(7, 19); // Maryland
    states.addEdge(7, 29); // New Jersey


    // Florida
    states.addEdge(8, 0);  // Alabama
    states.addEdge(8, 9);  // Georgia

    // Georgia
    states.addEdge(9, 0);  // Alabama
    states.addEdge(9, 8);  // Florida
    states.addEdge(9, 32); // North Carolina
    states.addEdge(9, 39); // South Carolina
    states.addEdge(9, 41); // Tennessee

    // Idaho
    states.addEdge(11, 27); // Nevada
    states.addEdge(11, 36); // Oregon
    states.addEdge(11, 43); // Utah
    states.addEdge(11, 46); // Washington
    states.addEdge(11, 49); // Wyoming
    states.addEdge(11, 25); // Montana

    // Illinois
    states.addEdge(12, 13); // Indiana
    states.addEdge(12, 24); // Missouri
    states.addEdge(12, 14); // Iowa
    states.addEdge(12, 16); // Kentucky
    states.addEdge(12, 48); // Wisconsin

    // Indiana
    states.addEdge(13, 12); // Illinois
    states.addEdge(13, 16); // Kentucky
    states.addEdge(13, 34); // Ohio
    states.addEdge(13, 21); // Michigan


    // Iowa
    states.addEdge(14, 13); // Illinois
    states.addEdge(14, 42); // Wisconsin
    states.addEdge(14, 40);  // South Dakota
    states.addEdge(14, 26);  // Nebraska
    states.addEdge(14, 22);  // Minnesota
    states.addEdge(14, 24);  // Missouri


    // Kansas
    states.addEdge(15, 24); // Missouri
    states.addEdge(15, 26); // Nebraska
    states.addEdge(15, 5); // Colorado
    states.addEdge(15, 35); // Oklahoma

    // Kentucky
    states.addEdge(16, 24);  // Missouri
    states.addEdge(16, 12); // Illinois
    states.addEdge(16, 13); // Indiana
    states.addEdge(16, 34); // Ohio
    states.addEdge(16, 47); // West Virginia
    states.addEdge(16, 45); // Virginia
    states.addEdge(16, 41); // Tennessee

    // Louisiana
    states.addEdge(17, 3);  // Arkansas
    states.addEdge(17, 23); // Mississippi
    states.addEdge(17, 42); // Texas

    // Maine
    states.addEdge(18, 28); // New Hampshire

    // Maryland
    states.addEdge(19, 7); // Delaware
    states.addEdge(19, 37); // Pennsylvania
    states.addEdge(19, 29); // New Jersey
    states.addEdge(19, 47); // West Virginia
    states.addEdge(19, 45); // Virginia

    // Massachusetts
    states.addEdge(20, 6);  // Connecticut
    states.addEdge(20, 38); // Rhode Island
    states.addEdge(20, 28); // New Hampshire
    states.addEdge(20, 19); // Maryland

    // Michigan
    states.addEdge(21, 13); // Indiana
    states.addEdge(21, 34); // Ohio
    states.addEdge(21, 46); // Wisconsin

    // Minnesota
    states.addEdge(22, 14); // Iowa
    states.addEdge(22, 46); // Wisconsin
    states.addEdge(22, 33); // North Dakota
    states.addEdge(22, 40); // South Dakota

    // Mississippi
    states.addEdge(23, 0);  // Alabama
    states.addEdge(23, 3);  // Arkansas
    states.addEdge(23, 17); // Louisiana
    states.addEdge(23, 41); // Tennessee

    // Missouri
    states.addEdge(24, 3);  // Arkansas
    states.addEdge(24, 41); // Tennessee
    states.addEdge(24, 12); // Illinois
    states.addEdge(24, 14); // Iowa
    states.addEdge(24, 15); // Kansas
    states.addEdge(24, 16); // Kentucky
    states.addEdge(24, 35); // Oklahoma
    states.addEdge(24, 26); // Nebraska

    // Montana
    states.addEdge(25, 11); // Idaho
    states.addEdge(25, 40); // South Dakota
    states.addEdge(25, 33); // North Dakota
    states.addEdge(25, 39); // Wyoming

    // Nebraska
    states.addEdge(26, 14); // Iowa
    states.addEdge(26, 40); // South Dakota
    states.addEdge(26, 5);  // Colorado
    states.addEdge(26, 15); // Kansas
    states.addEdge(26, 24); // Missouri
    states.addEdge(26, 49); // Wyoming

    // Nevada
    states.addEdge(27, 11); // Idaho
    states.addEdge(27, 4);  // California
    states.addEdge(27, 36); // Oregon
    states.addEdge(27, 43); // Utah
    states.addEdge(27, 2); // Arizona

    // New Hampshire
    states.addEdge(28, 20); // Massachusetts
    states.addEdge(28, 18); // Maine
    states.addEdge(28, 44); // Vermont

    // New Jersey
    states.addEdge(29, 7);  // Delaware
    states.addEdge(29, 37); // Pennsylvania
    states.addEdge(29, 19); // Maryland
    states.addEdge(29, 31); // New York

    // New Mexico
    states.addEdge(30, 2);  // Arizona
    states.addEdge(30, 5);  // Colorado
    states.addEdge(30, 35); // Oklahoma
    states.addEdge(30, 42); // Texas

    // New York
    states.addEdge(31, 20); // Massachusetts
    states.addEdge(31, 44); // Vermont
    states.addEdge(31, 6); // Connecticut
    states.addEdge(31, 37); // Pennsylvania
    states.addEdge(31, 29); // New Jersey


    // North Carolina
    states.addEdge(32, 45); // Virginia
    states.addEdge(32, 41); // Tennessee
    states.addEdge(32, 9);  // Georgia
    states.addEdge(32, 39); // South Carolina

    // North Dakota
    states.addEdge(33, 22); // Minnesota
    states.addEdge(33, 40); // South Dakota
    states.addEdge(33, 25); // Montana

    // Ohio
    states.addEdge(34, 37); // Pennsylvania
    states.addEdge(34, 13); // Indiana
    states.addEdge(34, 21); // Michigan
    states.addEdge(34, 16); // Kentucky
    states.addEdge(34, 47); // West Virginia

    // Oklahoma
    states.addEdge(35, 3);  // Arkansas
    states.addEdge(35, 5);  // Colorado
    states.addEdge(35, 24); // Missouri
    states.addEdge(26, 15); // Kansas
    states.addEdge(26, 42); // Texas
    states.addEdge(26, 30); // New Mexico

    // Oregon
    states.addEdge(36, 4);  // California
    states.addEdge(36, 11); // Idaho
    states.addEdge(36, 27); // Nevada
    states.addEdge(36, 46); // Washington

    // Pennsylvania
    states.addEdge(37, 7);  // Delaware
    states.addEdge(37, 19); // Maryland
    states.addEdge(37, 29); // New Jersey
    states.addEdge(37, 47); // West Virginia
    states.addEdge(37, 34); // Ohio
    states.addEdge(37, 31); // New York


    // Rhode Island
    states.addEdge(38, 6);  // Connecticut
    states.addEdge(38, 20); // Massachusetts

    // South Carolina
    states.addEdge(39, 9);  // Georgia
    states.addEdge(39, 32); // North Carolina

    // South Dakota
    states.addEdge(40, 14); // Iowa
    states.addEdge(40, 22); // Minnesota
    states.addEdge(40, 26); // Nebraska
    states.addEdge(40, 33); // North Dakota
    states.addEdge(40, 49); // Wyoming
    states.addEdge(40, 25); // Montana


    // Tennessee
    states.addEdge(41, 24); // Missouri
    states.addEdge(41, 32); // North Carolina
    states.addEdge(41, 0);  // Alabama
    states.addEdge(41, 3);  // Arkansas
    states.addEdge(41, 9);  // Georgia
    states.addEdge(41, 23); // Mississippi
    states.addEdge(41, 45);  // Virginia
    states.addEdge(41, 16);  // Kentucky

    // Texas
    states.addEdge(42, 3);  // Arkansas
    states.addEdge(42, 17); // Louisiana
    states.addEdge(42, 30); // New Mexico
    states.addEdge(42, 35); // Oklahoma

    // Utah
    states.addEdge(43, 11); // Idaho
    states.addEdge(43, 27); // Nevada
    states.addEdge(43, 49); // Wyoming
    states.addEdge(43, 5); // Colorado
    states.addEdge(43, 2); // Arizona

    // Vermont
    states.addEdge(44, 31); // New York
    states.addEdge(44, 28); // New Hampshire
    states.addEdge(44, 20); // Massachusetts

    // Virginia
    states.addEdge(45, 19); // Maryland
    states.addEdge(45, 47); // West Virginia
    states.addEdge(45, 16);  // Kentucky
    states.addEdge(45, 41);  // Tennessee
    states.addEdge(45, 32);  // North Carolina

    // Washington
    states.addEdge(46, 11); // Idaho
    states.addEdge(46, 36); // Oregon

    // West Virginia
    states.addEdge(47, 16); // Kentucky
    states.addEdge(47, 34); // Ohio
    states.addEdge(47, 37); // Pennsylvania
    states.addEdge(47, 19); // Maryland
    states.addEdge(47, 45); // Virginia

    // Wisconsin
    states.addEdge(48, 12); // Illinois
    states.addEdge(48, 14); //Iowa
    states.addEdge(48, 21); // Michigan
    states.addEdge(48, 22); // Minnesota

    // Wyoming
    states.addEdge(49, 5); // Colorado
    states.addEdge(49, 11); // Idaho
    states.addEdge(49, 25); // Montana
    states.addEdge(49, 26); // Nebraska
    states.addEdge(49, 40); // South Dakota
    states.addEdge(49, 43); // Utah

    // District of Columbia
    states.addEdge(50, 45); // Virginia
    states.addEdge(50, 19); // Maryland

    vector<int> bfs;
    states.BFS(5, &bfs);
    cout << "BFS" << endl;
    for(int s : bfs) {
        cout << state[s] << " ";
    }
    cout << endl << endl;

    vector<int> dfs;
    states.DFS(5, &dfs);
    cout << "DFS: " << endl;
    for(int s : dfs) {
        cout << state[s] << " ";
    }
    cout << endl << endl;

    string province[13];
    province[0] = "Alberta";
    province[1] = "British Columbia";
    province[2] = "Manitoba";
    province[3] = "New Brunswick";
    province[4] = "Newfoundland and Labrador";
    province[5] = "Northwest Territories";
    province[6] = "Nova Scotia";
    province[7] = "Nunavut";
    province[8] = "Ontario";
    province[9] = "Prince Edward Island";
    province[10] = "Quebec";
    province[11] = "Saskatchewan";
    province[12] = "Yukon";

    Graph provinces(13);

    provinces.addEdge(0, 1);
    provinces.addEdge(0, 11);
    provinces.addEdge(0, 5);
    provinces.addEdge(1, 5);
    provinces.addEdge(2, 8);
    provinces.addEdge(2, 11);
    provinces.addEdge(2, 7);
    provinces.addEdge(3, 6);
    provinces.addEdge(3, 9);
    provinces.addEdge(3, 10);
    provinces.addEdge(4, 10);
    provinces.addEdge(5, 7);
    provinces.addEdge(6, 9);
    provinces.addEdge(8, 10);
    provinces.addEdge(11, 5);
    provinces.addEdge(12, 5);
    provinces.addEdge(12, 2);

    vector<int> bfs2;
    provinces.BFS(10, &bfs2);
    cout << "BFS" << endl;
    for(int s : bfs2) {
        cout << province[s] << " ";
    }
    cout << endl << endl;

    vector<int> dfs2;
    provinces.DFS(10, &dfs2);
    cout << "DFS: " << endl;
    for(int s : dfs2) {
        cout << province[s] << " ";
    }
    cout << endl << endl;


    return 0;
}
