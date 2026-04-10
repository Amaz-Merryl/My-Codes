#include <iostream>
#include <string>
using namespace std;

class CNode;
class CAVL;

class CTrainTicket {
    friend class CNode;
    friend class CAVL;

private:
    string name;
    int age;
    string destination;
    int seatNo;

public:
    CTrainTicket();
    CTrainTicket(string, int, string, int);
    CTrainTicket(const CTrainTicket &other);
    ~CTrainTicket();
    void display();
};

class CNode {
    friend class CAVL;

private:
    CTrainTicket data;
    CNode* left;
    CNode* right;
    int height;

public:
    CNode();
    CNode(const CTrainTicket &s);
    ~CNode();
    void displayNode();
};

class CAVL {
private:
    CNode* root;

    int getHeight(CNode* node);
    int getBF(CNode* node);
    CNode* LLRotate(CNode* k3);
    CNode* RRRotate(CNode* k3);
    CNode* LRRotate(CNode* k3);
    CNode* RLRotate(CNode* k3);

    CNode* insertNode(CNode* node, CNode* newNode);

public:
    CAVL();
    ~CAVL();
    int isEmpty();
    void insert(CTrainTicket t);
    int search(int);
    CNode* findMax(CNode* );
    CNode* findMin(CNode* );
    void inOrder(CNode* temp);
    void preOrder(CNode* temp);
    void postOrder(CNode* temp);
    CNode* getRoot();
};

// ===== CTrainTicket =====
CTrainTicket::CTrainTicket() {
    name = "";
    age = 0;
    destination = "";
    seatNo = 0;
}

CTrainTicket::CTrainTicket(string n, int a, string d, int s) {
    name = n;
    age = a;
    destination = d;
    seatNo = s;
}

CTrainTicket::CTrainTicket(const CTrainTicket &other) {
    name = other.name;
    age = other.age;
    destination = other.destination;
    seatNo = other.seatNo;
}

CTrainTicket::~CTrainTicket() {}

void CTrainTicket::display() {
    cout << name << "\t\t" << age << "\t\t" << destination << "\t\t" << seatNo << endl << endl;
}

// ===== CNode =====
CNode::CNode() {
    left = NULL;
    right = NULL;
    height = 1;
}

CNode::CNode(const CTrainTicket &t) {
    data = t;
    left = NULL;
    right = NULL;
    height = 1;
}

CNode::~CNode() {}

void CNode::displayNode() {
    data.display();
}

// ===== CAVL =====
CAVL::CAVL() : root(NULL) {}

CAVL::~CAVL() {
    root = NULL;
}

int CAVL::isEmpty() {
    return root == NULL;
}

int CAVL::getHeight(CNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int CAVL::getBF(CNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Rotations
CNode* CAVL::LLRotate(CNode* k3) {
    CNode* k2 = k3->left;
    CNode* temp = k2->right;

    k2->right = k3;
    k3->left = temp;

    k3->height = max(getHeight(k3->left), getHeight(k3->right)) + 1;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    cout<<"LL Rotation completed..!\n";

    return k2;
}

CNode* CAVL::RRRotate(CNode* k3) {
    CNode* k2 = k3->right;
    CNode* temp = k2->left;

    k2->left = k3;
    k3->right = temp;

    k3->height = max(getHeight(k3->left), getHeight(k3->right)) + 1;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    cout<<"RR Rotation completed...! \n";

    return k2;
}

CNode* CAVL::LRRotate(CNode* k3) {
    k3->left = RRRotate(k3->left);
    cout<<"LR Rotation Completed...!\n";
    return LLRotate(k3);
}

CNode* CAVL::RLRotate(CNode* k3) {
    k3->right = LLRotate(k3->right);
    cout<<"RL Rotation Completed..!\n";
    return RRRotate(k3);
}

// Recursive insert
CNode* CAVL::insertNode(CNode* node, CNode* newNode) {
    if (node == NULL)
        return newNode;

    if (newNode->data.seatNo < node->data.seatNo)
        node->left = insertNode(node->left, newNode);
    else if (newNode->data.seatNo > node->data.seatNo)
        node->right = insertNode(node->right, newNode);
    else
        return node; // Duplicate seatNo not allowed

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBF(node);

    // LL
    if (balance > 1 && newNode->data.seatNo < node->left->data.seatNo)
        return LLRotate(node);

    // RR
    if (balance < -1 && newNode->data.seatNo > node->right->data.seatNo)
        return RRRotate(node);

    // LR
    if (balance > 1 && newNode->data.seatNo > node->left->data.seatNo)
        return LRRotate(node);

    // RL
    if (balance < -1 && newNode->data.seatNo < node->right->data.seatNo)
        return RLRotate(node);

    return node;
}

void CAVL::insert(CTrainTicket t) {
    CNode* newNode = new CNode(t);
    root = insertNode(root, newNode);
}

int CAVL::search(int key) {
    CNode* temp = root;
    while (temp != NULL) {
        if (key == temp->data.seatNo) {
            temp->displayNode();
            return 1;
        }
        else if (key < temp->data.seatNo)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return -1;
}

CNode* CAVL::findMax(CNode* temp) {
    if (temp == NULL) return NULL;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

CNode* CAVL::findMin(CNode* temp) {
    if (temp == NULL) return NULL;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

// Traversals
void CAVL::inOrder(CNode* temp) {
    if (temp != NULL) {
        inOrder(temp->left);
        temp->data.display();
        inOrder(temp->right);
    }
}

void CAVL::preOrder(CNode* temp) {
    if (temp != NULL) {
        temp->data.display();
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void CAVL::postOrder(CNode* temp) {
    if (temp != NULL) {
        postOrder(temp->left);
        postOrder(temp->right);
        temp->data.display();
    }
}

CNode* CAVL::getRoot() {
    return root;
}
int main() {
    CAVL tree;
    int choice;

    cout<<"   ________________________________________________\n";
    cout<<"   |                    AVL                       |\n";
    cout<<"   |______________________________________________|\n";
    cout<<"   ************************************************\n";
    cout<<"    *     1. Insertion                            *\n";
    cout<<"    *     2. Search                               *\n";
    cout<<"    *     3. Inorder                              *\n";
    cout<<"    *     4. Preorder                             *\n";
    cout<<"    *     5. Postorder                            *\n";
    cout<<"    *     6. Find Min                             *\n";
    cout<<"    *     7. Find Max                             *\n";
    cout<<"    *     8. Get Root                             *\n";
    cout<<"   ************************************************\n";
    cout<<"   *        0. Exit                               *\n";
    cout<<"   ************************************************\n\n";

    do {
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string n, d;
                int a, s;
                cout << "Name : ";
                cin >> n;
                cout << "Age : ";
                cin >> a;
                cout << "Destination : ";
                cin >> d;
                cout << "Seat No. : ";
                cin >> s;

                CTrainTicket t(n, a, d, s);
                tree.insert(t);
                cout << "Inserted.\n";
                break;
            }

            case 2: {
                int s;
                cout << "Enter seatNo to search: ";
                cin >> s;
                cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                cout << "==============================================================\n";

                int result = tree.search(s);
                if (result == 1)
                    cout << "Found.\n";
                else
                    cout << "Not found!\n";
                break;
            }

            case 3:
                cout << "InOrder Traversal\n";
                cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                cout << "==============================================================\n";
                tree.inOrder(tree.getRoot());
                break;

            case 4:
                cout << "PreOrder Traversal:\n";
                cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                cout << "==============================================================\n";
                tree.preOrder(tree.getRoot());
                break;

            case 5:
                cout << "PostOrder Traversal:\n";
                cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                cout << "==============================================================\n";
                tree.postOrder(tree.getRoot());
                break;

            case 6: {
                CNode* result = tree.findMin(tree.getRoot());
                if (result == NULL)
                    cout << "Error: Tree is Empty\n";
                else {
                    cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                    cout << "==============================================================\n";
                    result->displayNode();
                }
                break;
            }

            case 7: {
                CNode* result = tree.findMax(tree.getRoot());
                if (result == NULL)
                    cout << "Tree is Empty\n";
                else {
                    cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                    cout << "==============================================================\n";
                    result->displayNode();
                }
                break;
            }

            case 8: {
                CNode* root = tree.getRoot();
                if (root != NULL) {
                    cout << "Name\t\tAge\t\tDestination\t\tSeat No.\n";
                    cout << "==============================================================\n";
                    root->displayNode();
                }
                else {
                    cout << "Empty TREE" << endl;
                }
                break;
            }

            case 0:
                cout << "Exiting....\n";
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
