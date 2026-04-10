#include <iostream>
#include <string>
using namespace std;


class CTrainTicket {
    friend class Node;
    friend class TrainGraph;
private:
    string name, dest;
    int age, seat;
public:
    void input();
    void show();
    int getSeat();
};


class Queue {
    int arr[100];
    int front, rear;
public:
    Queue();
    void push(int x);
    int pop();
    bool empty();
};


class Node {
    friend class TrainGraph;
    CTrainTicket t;
    Node* next;
public:
    Node(CTrainTicket x);
};


class TrainGraph {
    Node** list;
    int n;

    int find(int seat);
    void sortOneList(int i);
    void dfs(int v, bool vis[]);

public:
    TrainGraph(int size);
    ~TrainGraph();

    void addPassengers();
    void addEdges();
    void BFS(int start);
    void DFS(int start);
};

void CTrainTicket::input() {
    cout << "  Name       : "; cin >> name;
    cout << "  Age        : "; cin >> age;
    cout << "  Destination: "; cin >> dest;
    cout << "  Seat No    : "; cin >> seat;
}

void CTrainTicket::show() {
    cout << "  " << name;
    for (int i = name.length(); i < 10; i++) cout << " ";
    cout << age;
    for (int i = 0; i < 8; i++) cout << " ";
    cout << dest;
    for (int i = dest.length(); i < 12; i++) cout << " ";
    cout << seat << endl;
}

int CTrainTicket::getSeat() { return seat; }

Queue::Queue() { front = rear = -1; }

void Queue::push(int x) {
    arr[++rear] = x;
    if (front == -1) front = 0;
}

int Queue::pop() {
    return (front > rear) ? -1 : arr[front++];
}

bool Queue::empty() { return front > rear; }


Node::Node(CTrainTicket x) : t(x), next(NULL) {}

TrainGraph::TrainGraph(int size) : n(size) {
    list = new Node*[n];
    for (int i = 0; i < n; i++) list[i] = NULL;
}

TrainGraph::~TrainGraph() {
    for (int i = 0; i < n; i++) {
        Node* p = list[i];
        while (p) {
            Node* t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] list;
}

int TrainGraph::find(int seat) {
    for (int i = 0; i < n; i++)
        if (list[i]->t.getSeat() == seat) return i;
    return -1;
}

void TrainGraph::sortOneList(int i) {
    Node* h = list[i]->next;
    if (!h || !h->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* p = NULL;
        Node* c = h;
        while (c->next) {
            if (c->t.getSeat() > c->next->t.getSeat()) {
                Node* temp = c->next;
                c->next = temp->next;
                temp->next = c;
                if (!p) h = temp;
                else p->next = temp;
                p = temp;
                swapped = true;
            } else {
                p = c;
                c = c->next;
            }
        }
    } while (swapped);
    list[i]->next = h;
}

void TrainGraph::addPassengers() {
    cout << "\n=== ENTER " << n << " PASSENGERS ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nPassenger " << i << ":\n";
        CTrainTicket x;
        x.input();
        list[i] = new Node(x);
    }
}

void TrainGraph::addEdges() {
    int edges;
    cout << "\nHow many connections (edges)? ";
    cin >> edges;

    cout << "\n=== ENTER " << edges << " CONNECTIONS ===\n";
    for (int i = 0; i < edges; i++) {
        int a, b;
        cout << "\nConnection " << i + 1 << ":\n";
        cout << "  From index: "; cin >> a;
        cout << "  To   index: "; cin >> b;

        if (a >= 0 && a < n && b >= 0 && b < n && a != b) {
            Node* n1 = new Node(list[b]->t);
            n1->next = list[a]->next;
            list[a]->next = n1;

            Node* n2 = new Node(list[a]->t);
            n2->next = list[b]->next;
            list[b]->next = n2;

            cout << "  Connected Seat " << list[a]->t.getSeat()
                 << " <-> " << list[b]->t.getSeat() << endl;
        } else {
            cout << "  Invalid indices! Skipping this edge.\n";
            i--;
        }
    }

    for (int i = 0; i < n; i++) {
        sortOneList(i);
    }
}

void TrainGraph::BFS(int start) {
    if (start < 0 || start >= n) {
        cout << "Bad start index!\n";
        return;
    }
    bool vis[100] = {false};
    Queue q;

    q.push(start);
    vis[start] = true;

    cout << "\n" << string(70, '=') << "\n";
    cout << "                BFS - SEAT ORDER (Normal Queue)               \n";
    cout << string(70, '=') << "\n";
    cout << "  Name       Age      Destination     SeatNo\n";
    cout << string(70, '-') << "\n";

    while (!q.empty()) {
        int v = q.pop();
        if (v == -1) continue;
        list[v]->t.show();

        Node* p = list[v]->next;
        while (p) {
            int idx = find(p->t.getSeat());
            if (idx != -1 && !vis[idx]) {
                q.push(idx);
                vis[idx] = true;
            }
            p = p->next;
        }
    }
    cout << string(70, '=') << "\n\n";
}

void TrainGraph::dfs(int v, bool vis[]) {
    vis[v] = true;
    list[v]->t.show();

    Node* p = list[v]->next;
    while (p) {
        int idx = find(p->t.getSeat());
        if (idx != -1 && !vis[idx]) dfs(idx, vis);
        p = p->next;
    }
}

void TrainGraph::DFS(int start) {
    if (start < 0 || start >= n) {
        cout << "Bad start index!\n";
        return;
    }
    bool vis[100] = {false};
    cout << string(70, '=') << "\n";
    cout << "                DFS - SEAT ORDER (Recursion)                \n";
    cout << string(70, '=') << "\n";
    cout << "  Name       Age      Destination     SeatNo\n";
    cout << string(70, '-') << "\n";

    dfs(start, vis);

    cout << string(70, '=') << "\n\n";
}


int main() {
    int n;
    cout << "==================================\n";
    cout << " TRAIN TICKET - SEAT GRAPH APP\n";
    cout << "==================================\n";
    cout << "Passengers? ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of passengers!\n";
        return 1;
    }

    TrainGraph g(n);
    g.addPassengers();
    g.addEdges();

    int s;
    cout << "\nStart from index (0-" << n-1 << "): ";
    cin >> s;

    if (s < 0 || s >= n) {
        cout << "Invalid start index!\n";
    } else {
        g.BFS(s);
        g.DFS(s);
    }


    return 0;
}