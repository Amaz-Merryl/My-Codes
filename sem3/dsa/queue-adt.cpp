#include<iostream>
#include<string>
using namespace std;
class CAQueue;
class CTrainTicket
{
    public:
        CTrainTicket();
        ~CTrainTicket();
        void getData();
        void displayData(int);
    private:
        string name;
        int age;
        string destination;
        int seatNo;
        friend class CAQueue;
};
class CAQueue
{
   public:
      CAQueue();
      ~CAQueue();
      int isFull();
      int isEmpty();
      int enqueue(CTrainTicket);
      int dequeue();
      int peekAtFront();
      int peekAtRear();
      int size();
      int displayQueue();
      int makeQueueEmpty();
   private:
      CTrainTicket* Queuearr;
      int front;
      int rear;
      int capacity;
};
CTrainTicket::CTrainTicket()
{
    name="";
    age=0;
    destination="";
    seatNo=0;
}
CTrainTicket::~CTrainTicket()
{
}
void CTrainTicket::getData()
{
    cout << "Name : ";
    getline(cin,name);
    cout << "Age : ";
    cin>>age;
    cout << "Destination : ";
    cin.ignore();
    getline(cin,destination);
    cout << "Seat No. : ";
    cin >> seatNo;
    cin.ignore();
}
void CTrainTicket::displayData(int s)
{
    cout << s << ".\t|\t" << name << "\t|\t" << age << "\t|\t" << destination << "\t\t|\t" << seatNo <<endl;
}
CAQueue::CAQueue(/*int c*/)
{
    capacity = 5;
    Queuearr = new CTrainTicket[capacity];
    front = -1;
    rear = -1;
}
CAQueue::~CAQueue()
{
    delete[] Queuearr;
}
int CAQueue::isFull()
{
    if((rear+1)%capacity == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CAQueue::isEmpty()
{
    if(front == -1 and rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CAQueue::enqueue(CTrainTicket ele)
{
    if(isFull())
    {
        return -1;
    }
    else if(isEmpty())
    {
        front = 0;
        rear = 0;
        Queuearr[0] = ele;
        return 1;
    }
    else
    {
        rear = (rear+1)%capacity;
        Queuearr[rear] = ele;
        return 2;
    }
}
int CAQueue::dequeue()
{
    if(isEmpty())
    {
        return -1;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
        return 1;
    }
    else
    {
        cout << "S.No.\t|\tName\t|\tAge\t|\tDestination\t|\tSeat No.\t|\t" << endl;
        cout <<"-------------------------------------------------------------------------------------------" << endl;
       Queuearr[front].displayData(front+1);
       front = (front+1)%capacity;
        return 2;
    }
}
int CAQueue::peekAtFront()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Queuearr[front].displayData(front+1);
        return 1;
    }
}
int CAQueue::size()
{
    if(isEmpty())
    {
       return -1;
    }
    else
    {
       return (rear - front + capacity) % capacity + 1;
    }
}
int CAQueue::displayQueue()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        cout << "S.No.\t|\tName\t|\tAge\t|\tDestination\t|\tSeat No.\t|\t" << endl;
        cout <<"-------------------------------------------------------------------------------------------" << endl;
        int s = size();
        int i = front;
        for (int k = 0; k < s; k++)
        {
            Queuearr[i].displayData(i+1);
            i = (i + 1) % capacity;
        }
    return 1;
    }

}
int CAQueue::makeQueueEmpty()
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

int CAQueue::peekAtRear()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Queuearr[rear].displayData(rear+1);
        return 1;
    }
}
int main()
{
   /*int c;
    cout << "Enter Queue capacity: " << endl;
    cin >> c;*/
   CAQueue obj;
   int choice;
   CTrainTicket t;
   cout<<"   ________________________________________________\n";
   cout<<"   |            Queue ADT Using Array             |\n";
   cout<<"   |______________________________________________|\n";
   cout<<"   ************************************************\n";
   cout<<"    *     1.Check Full.                          *\n";
   cout<<"    *     2.Check Empty.                         *\n";
   cout<<"    *     3.Enqueue.                             *\n";
   cout<<"    *     4.Dequeue                              *\n";
   cout<<"    *     5.Peek At Front.                       *\n";
   cout<<"    *     6.size.                                *\n";
   cout<<"    *     7.Display Queue.                       *\n";
   cout<<"    *     8.Make Queue Empty.                    *\n";
   cout<<"    *     9.Peek At Rear.                        *\n";
   cout<<"   ************************************************\n";
   cout<<"   *        0. Exit!                              *\n";
   cout<<"   ************************************************\n\n";
    do
    {
        cout << "\n\tEnter the Choice : " ;
        cin >> choice;

        if(choice == 1)
        {
            if(obj.isFull() == 1)
            {
                cout << "Queue is Full" << endl;
            }
            else
            {
                cout << "Queue is Not Full" << endl;
            }
        }
        else if(choice ==2)
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
        else if(choice == 3)
        {
            cin.ignore();
            CTrainTicket t;
            t.getData();
            int e;
            e = obj.enqueue(t);
            if(e == -1)
            {
                cout << "The Queue is full..!" << endl;
            }
            /*else if(e == 1)
            {
                cout << "at first" << endl;
            }*/
            else
            {
                cout << "Enqueued successfull" << endl;
            }
        }
        else if(choice == 4)
        {
            int d;
            d = obj.dequeue();
            if(d == -1)
            {
                cout << "The Queue is already empty..!" << endl;
            }
            /*else if(d == 1)
            {
                cout << "As the Queue contains only one object it is dequeued successfully" << endl;
            }*/
            else
            {
                cout << "Dequeued successfull" << endl;
            }
        }
        else if(choice == 5)
        {
            int o;
            o = obj.peekAtFront();
            if(o == -1)
            {
                cout << "The Queue is empty..!" << endl;
            }
        }
        else if(choice == 6)
        {
            cout << "The Size of the Queue:" << obj.size() << endl;
        }
        else if(choice == 7)
        {
            int p;
            p = obj.displayQueue();
            if(p == -1)
            {
                cout << "The Queue is empty..!" << endl;
            }
        }
        else if(choice == 8)
        {
            if(obj.makeQueueEmpty() == -1)
            {
                cout << "Queue is already empty..!" << endl;
            }
            else
            {
                cout << " Queue is now made empty" << endl;
            }
        }
        else if(choice == 9)
        {
           int a=obj.peekAtRear();
           if(a==-1)
              cout<<"Empty.\n";
        }

        else if(choice == 0)
        {
            cout << "Exiting ..." << endl;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }while(choice != 0 );
}
