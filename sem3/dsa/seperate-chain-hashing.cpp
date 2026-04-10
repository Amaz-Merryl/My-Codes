#include<iostream>
#include<vector>
using namespace std;

class CTrainTicket
{
    friend class CSeparateHashing;
private:
    int seatNo;
    string name;
    int age;
public:
    CTrainTicket() { seatNo = -1; }
    ~CTrainTicket() {}
    void get() {
        cout << "Enter seatNo, name and age: ";
        cin >> seatNo >> name >> age;
    }
    int getseatNo() { return seatNo; }
    void display(int i)
    {
        cout << "|" << i << "\t\t|" << seatNo << "\t\t|" << name << "\t\t|" << age << "\t|\n";
    }
};

// Node for linked list (used in separate chaining)
class Node
{
public:
    CTrainTicket data;
    Node* next;
    Node(CTrainTicket s)
    {
        data = s;
        next = NULL;
    }
};

class CSeparateHashing
{
private:
    int tableSize;
    int size;
    Node** table; // array of linked list heads
public:
    CSeparateHashing(int);
    ~CSeparateHashing();
    int insert(CTrainTicket);
    int deleteTicket(int);
    int search(int);
    void display();
    int isFull();
    int isEmpty();
};

CSeparateHashing::CSeparateHashing(int t)
{
    tableSize = t;
    size = 0;
    table = new Node*[tableSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = NULL;
}

CSeparateHashing::~CSeparateHashing()
{
    for (int i = 0; i < tableSize; i++)
    {
        Node* temp = table[i];
        while (temp)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
    delete[] table;
    table = NULL;
    tableSize = 0;
    size = 0;
}

int CSeparateHashing::isFull()
{
    // In separate chaining, theoretically never full
    return 0;
}

int CSeparateHashing::isEmpty()
{
    return (size == 0);
}

int CSeparateHashing::insert(CTrainTicket s)
{
    int K = s.getseatNo();
    int bucketId = K % tableSize;

    // Check for duplicate seat number
    Node* temp = table[bucketId];
    while (temp)
    {
        if (temp->data.getseatNo() == K)
            return -1; // Duplicate, not allowed
        temp = temp->next;
    }

    Node* newNode = new Node(s);
    newNode->next = table[bucketId];
    table[bucketId] = newNode;
    size++;
    return 1; // success
}

int CSeparateHashing::deleteTicket(int K)
{
    if (isEmpty()) return -2;

    int bucketId = K % tableSize;
    Node* temp = table[bucketId];
    Node* prev = NULL;

    while (temp)
    {
        if (temp->data.getseatNo() == K)
        {
            cout << "|=======================================================|\n";
            cout << "| Bucket ID \t| SeatNo. \t| Name \t\t| Age \t|\n";
            cout << "|=======================================================|\n";
            temp->data.display(bucketId);

            if (prev == NULL)
                table[bucketId] = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            size--;
            return 1; // deleted successfully
        }
        prev = temp;
        temp = temp->next;
    }
    return -1; // Not found
}

int CSeparateHashing::search(int K)
{
    if (isEmpty()) return -2;

    int bucketId = K % tableSize;
    Node* temp = table[bucketId];
    while (temp)
    {
        if (temp->data.getseatNo() == K)
        {
            cout << "|=======================================================|\n";
            cout << "| Bucket ID \t| SeatNo. \t| Name \t\t| Age \t|\n";
            cout << "|=======================================================|\n";
            temp->data.display(bucketId);
            return 1; // found
        }
        temp = temp->next;
    }
    return -1; // Not found
}

void CSeparateHashing::display()
{
    cout << "|=======================================================|\n";
    cout << "| Bucket ID \t| SeatNo. \t| Name \t\t| Age\t|\n";
    cout << "|=======================================================|\n";

    for (int i = 0; i < tableSize; i++)
    {
        if (table[i] == NULL)
        {
            cout << "|" << i << "\t\t|Empty\t\t|Empty\t\t|Empty\t|\n";
        }
        else
        {
            Node* temp = table[i];
            while (temp)
            {
                temp->data.display(i);
                temp = temp->next;
            }
        }
    }
}
int main()
{
    CTrainTicket data;
    int size;
    cout << "Enter the Size of the Table : ";
    cin >> size;
    CSeparateHashing obj(size);
    int ch, k;

    cout << "   ________________________________________________\n";
    cout << "   |            Separate Chaining Hashing          |\n";
    cout << "   |______________________________________________|\n";
    cout << "   ************************************************\n";
    cout << "    *     1. Is Full                             *\n";
    cout << "    *     2. Is Empty                            *\n";
    cout << "    *     3. Insert                              *\n";
    cout << "    *     4. Delete                              *\n";
    cout << "    *     5. Display                             *\n";
    cout << "    *     6. Search                              *\n";
    cout << "   ************************************************\n";
    cout << "   *     0. Exit                                  *\n";
    cout << "   ************************************************\n";

    do
    {
        cout << "\n\tEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int a = obj.isFull();
            if (a == 1)
                cout << "Table is Full..!\n";
            else
                cout << "Not Full..!\n";
            break;
        }
        case 2:
        {
            int a = obj.isEmpty();
            if (a == 1)
                cout << "Table is Empty..!\n";
            else
                cout << "Not Empty..!\n";
            break;
        }
        case 3:
        {
            data.get();
            int a = obj.insert(data);
            if (a == -1)
                cout << "Can't insert..!\n";
            else if (a == -2)
                cout << "Table is Full..!\n";
            break;
        }
        case 4:
        {
            cout << "Enter the Seat No. to delete Ticket : ";
            cin >> k;
            int a = obj.deleteTicket(k);
            if (a == -1)
                cout << "Deletion Not Possible..!\n";
            else if (a == -2)
                cout << "Table is Empty..!\n";
            else
                cout << "Deleted..!\n";
            break;
        }
        case 5:
        {
            obj.display();
            break;
        }
        case 6:
        {
            cout << "Enter the Seat No. to Search : ";
            cin >> k;
            int a = obj.search(k);
            if (a == -2)
                cout << "Table is Empty..!\n";
            else if (a == -1)
                cout << "Seat No. Not Found..!\n";
            else
                cout << "Found..!\n";
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (ch != 0);

    return 0;
}