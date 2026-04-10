#include<iostream>
#include<string>
using namespace std;
class CLQueue;
class CNode;
class CTrainTicket
{
    public:
        CTrainTicket();
        ~CTrainTicket();
        void getData();
        void displayData();
    private:
        string name;
        int age;
        string destination;
        int seatNo;
        friend class CNode;
};
class CNode
{
    public:
       CNode();
       CNode(CTrainTicket,CNode *);
       ~CNode();
       void get();
       void display();
    private:
       CTrainTicket data;
       CNode *next;
       friend class CLQueue;
};
class CLQueue
{
    public:
       CLQueue();
       ~CLQueue();
       int isEmpty();
       int enqueue(CNode *newNode);
       int dequeue();
       int peek();
       int size();
       void displayQueue();
       int makeQueueEmpty();
    private:
       CNode *front;
       CNode *rear;
};
CTrainTicket::CTrainTicket()
{
    name = "";
    age = 0;
    destination = "";
    seatNo = 0;
}
CTrainTicket::~CTrainTicket()
{
}
void CTrainTicket::getData()
{
    cout << "Name : " ;
    cin>>name;
    cout << "Age : " ;
    cin>>age;
    cout << "Destination : ";
    cin>>destination;
    cout << "Seat No : ";
    cin >> seatNo;
}
void CTrainTicket::displayData()
{
    cout << name << "\t|\t" << age << "\t|\t" << destination << "\t\t|\t" << seatNo << endl;
}
CNode::CNode()
{
    next = NULL;
}
CNode::CNode(CTrainTicket t,CNode *n)
{
    data = t;
    next = n;
}
CNode::~CNode()
{
    next = NULL;
}
void CNode::get()
{
    data.getData();
}
void CNode::display()
{
    data.displayData();
}
CLQueue::CLQueue()
{
    front = NULL;
    rear = NULL;
}
CLQueue::~CLQueue()
{
    front = NULL;
    rear = NULL;
}

int CLQueue::isEmpty()
{
    if(front == NULL && rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CLQueue::enqueue(CNode *newNode)
{
    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
        return 1;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        return 2;
    }
}
int CLQueue::dequeue()
{
    if(isEmpty())
    {
        return -1;
    }
    else if(front == rear)
    {
        CNode *temp = front;
        cout << "Name.\t|\tAge.\t|\tDestination.\t|\tSeatNo" << endl;
        cout << "-----------------------------------------------------------\n";
        front->data.displayData();
        delete temp;
        temp = NULL;
        front = NULL;
        rear = NULL;
        return 1;
    }
    else
    {
        CNode *temp = front;
        cout << "Dequeued Data" <<endl;
        cout << "Name.\t|\tAge.\t|\tDestination.\t|\tSeatNo" << endl;
        cout << "-----------------------------------------------------------\n";
        front->data.displayData();
        front = front->next;
        delete temp;
        temp = NULL;
        return 2;
    }
}
int CLQueue::peek()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        cout << "Front Node:" <<endl;
        cout << "Name.\t|\tAge.\t|\tDestination.\t|\tSeatNo." << endl;
        cout << "-----------------------------------------------------------\n";
        front->data.displayData();
        cout << "Rear Node:" << endl;
        cout << "Name.\t|\tAge.\t|\tDestination.\t|\tSeatNo." << endl;
        cout << "------------------------------------------------------------\n";
        rear->data.displayData();
        return 1;
    }
}
int CLQueue::size()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        int count = 0;
        CNode* temp = front;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}
void CLQueue::displayQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty..!\n" << endl;
    }
    else
    {
        cout << "Name.\t|\tAge.\t|\tDestination.\t|\tSeatno." << endl;
        cout << "----------------------------------------------------------------------\n";
        CNode* temp = front;
        while (temp != NULL)
        {
            temp->data.displayData();
            temp = temp->next;
        }
        cout << endl;
    }
}
int CLQueue::makeQueueEmpty()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        while(!isEmpty())
        {
            dequeue();
        }
        return 1;
    }
}
int main()
{
    CLQueue obj;
    cout<<"   ________________________________________________\n";
    cout<<"   |        Queue ADT Using Linked Array          |\n";
    cout<<"   |______________________________________________|\n";
    cout<<"   ************************************************\n";
    cout<<"    *     1.Check Empty.                         *\n";
    cout<<"    *     2.Enqueue.                             *\n";
    cout<<"    *     3.Dequeue.                             *\n";
    cout<<"    *     4.Peek                                 *\n";
    cout<<"    *     5.size.                                *\n";
    cout<<"    *     6.Display Queue.                       *\n";
    cout<<"    *     7.Make Queue Empty.                    *\n";
    cout<<"   ************************************************\n";
    cout<<"   *        0. Exit!                              *\n";
    cout<<"   ************************************************\n\n";
    int choice;
    do
    {
        cout << "\n\tEnter the Choice:";
        cin >> choice;
        if(choice ==1)
        {
            if(obj.isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue is Not Empty" << endl;
            }
        }
        else if(choice == 2)
        {
            cin.ignore();
            CTrainTicket t;
            t.getData();
            CNode *newNode = new CNode(t,NULL);
            int e;
            e = obj.enqueue(newNode);
            if(e == 1)
            {
               cout<<"";
            }
            else
            {
                cout << "The object is enqueued successfully" << endl;
            }
        }
        else if(choice == 3)
        {
            int d;
            d = obj.dequeue();
            if(d == -1)
            {
                cout << "Queue is empty..!" << endl;
            }
            else if(d == 1)
            {
                cout<<"";
            }
            else
            {
                cout << "The Node is dequeued successfully" << endl;
            }
        }
        else if(choice == 4)
        {
            if(obj.peek() == -1)
            {
                cout << "Queue is empty..!" << endl;
            }
        }
        else if(choice == 5)
        {
            int s;
            s = obj.size();
            if(s == -1)
            {
                cout << "Queue is empty..!" << endl;
            }
            else
            {
                cout << "Size of Queue:" << s << endl;
            }
        }
        else if(choice == 6)
        {
            obj.displayQueue();
        }
        else if(choice == 7)
        {
            if(obj.makeQueueEmpty() == -1)
            {
                cout << "The Queue is already Empty" << endl;
            }
            else
            {
                cout << "The Queue is now made Empty" << endl;
            }
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }while(choice != 0);
}
