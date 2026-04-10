#include<iostream>
#include<string>
using namespace std;
class CLStack;
class CTrainTicket
{
    public:
        CTrainTicket();
        ~CTrainTicket();
        void getData();
        void displayData(int);
        //string destination;
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
       void display(int);
    private:
       CTrainTicket data;
       CNode *next;
       friend class CLStack;
};
class CLStack
{
    public:
       CLStack();
       ~CLStack();
       int isEmpty();
       int push(CNode *newNode);
       int pop();
       int peek();
       int displayStack();
       int makeStackEmpty();
       int size();
    private:
       CNode *top;
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
    cin.ignore();
    cout << "Name :";
    getline(cin,name);
    cout << "Age :";
    cin>>age;
    cin.ignore();
    cout << "Destination :";
    getline(cin,destination);
    cout << "Seat No. : ";
    cin >>seatNo;
    cin.ignore();
}
void CTrainTicket::displayData(int n)
{
    cout << n <<".\t|\t" << name << "\t|\t" << age << "\t|\t" << destination <<"\t\t|\t" <<  seatNo << endl;
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
void CNode::display(int n)
{
    data.displayData(n);
}
CLStack::CLStack()
{
    top = NULL;
}
CLStack::~CLStack()
{
    top = NULL;
}
int CLStack::isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CLStack::push(CNode *newNode)
{
    if(isEmpty())
    {
        top = newNode;
        return 1;
    }
    else
    {
        newNode->next = top;
        top = newNode;
        return 2;
    }
}
int CLStack::pop()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        CNode *temp = top;
        top = top->next;

      cout<<"S.No.\t|\tName\t|\tAge\t|\tDestination\t|\tSeat No."<<endl;
      cout<<"-------------------------------------------------------------------------------------------\n";
        temp->display(size()+1);
        delete temp;
        temp = NULL;
        return 1;
    }
}
int CLStack::displayStack()
{
   if(isEmpty())
      return -1;
   else
   {
      cout<<"S.No.\t|\tName\t|\tAge\t|\tDestination\t|\tSeat No."<<endl;
      cout<<"-------------------------------------------------------------------------------------------\n";
      CNode* temp = top;
      int c=size();
      while (temp != NULL)
      {
         temp->display(c);
         temp = temp->next;
         c--;
      }
      return 1;
   }
}
int CLStack::peek()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {

      cout<<"S.No.\t|\tName\t|\tAge\t|\tDestination\t|\tSeat No."<<endl;
      cout<<"-------------------------------------------------------------------------------------------\n";
       top->data.displayData(size());
       return 1;
    }
}
int CLStack::size()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        CNode *temp = top;
        int c = 1;
        while(temp->next != NULL)
        {
            temp = temp->next;
            c++;
        }
        return c;
    }
}
int CLStack::makeStackEmpty()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {

        while(!isEmpty())
        {
            pop();
        }
        return 1;
    }
}
int main()
{
   int ch;
   CLStack obj;
   CTrainTicket t;
   cout<<"   ________________________________________________\n";
   cout<<"   |        Stack ADT Using Linked List           |\n";
   cout<<"   |______________________________________________|\n";
   cout<<"   ************************************************\n";
   cout<<"    *     1.Display Stack.                       *\n";
   cout<<"    *     2.Check Empty.                         *\n";
   cout<<"    *     3.Size of the Stack.                   *\n";
   cout<<"    *     4.Push.                                *\n";
   cout<<"    *     5.Peek.                                *\n";
   cout<<"    *     6.Pop.                                 *\n";
   cout<<"    *     7.Make Stack Empty.                    *\n";
   cout<<"   ************************************************\n";
   cout<<"   *        0. Exit!                              *\n";
   cout<<"   ************************************************\n\n";
   do
   {
      cout<<"\n\tEnter the choice : ";
      cin>>ch;
      cout<<endl;
      switch(ch)
      {
         case 1:
         {
            int a=obj.displayStack();
            if(a==-1)
            {
               cout<<"Stack Is Empty..!\n";
            }
            break;
         }
         case 2:
         {
            int a=obj.isEmpty();
            if(a==1)
               cout<<"Stack is Empty..!\n";
            else
               cout<<"Stack is Not Empty..!\n";
            break;
         }
         case 3:
         {
            int a=obj.size();
            if(a==0)
               cout<<"Stack is Empty..!\n";
            else
               cout<<"Size : "<<a<<endl;
            break;
         }
         case 4:
         {
            t.getData();
            CNode *n=new CNode(t,NULL);
            int a=obj.push(n);
            if(a==-1)
               cout<<"Stack Full Can`t insert..!\n";
            break;
         }
         case 5:
         {
            int a=obj.peek();
            if(a==-1)
               cout<<"Stack is Empty..!\n";
            break;
         }
         case 6:
         {
            int a=obj.pop();
            if(a==-1)
               cout<<"Stack is Empty..!\n";
            break;
         }
         case 7:
         {
            int a=obj.makeStackEmpty();
            if(a==-1)
               cout<<"Stack is Already Empty..!\n";
            else
               cout<<"Successfull..!\n";
            break;
         }
         default:
         {
            cout<<"Invalid Case ...!";
            break;
         }

      }
   }while(ch!=0);
}
