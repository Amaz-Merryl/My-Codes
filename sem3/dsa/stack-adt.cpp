#include<iostream>
using namespace std;
class CTrainTicket
{
   public:
      CTrainTicket();
      ~CTrainTicket();
      void getData();
      void displayData(int);
   private:
      int age;
      string name;
      int seatNo;
      string destination;
      friend class CAStack;

};
class CAStack
{
   public:
      CAStack();
      ~CAStack();
      int push(CTrainTicket);
      int pop();
      int peek();
      int display();
      int isFull();
      int isEmpty();
      int size();
      int makeStackEmpty();
   private:
      int top;
      int capacity;
      CTrainTicket *stackarr;
};
CTrainTicket::CTrainTicket()
{
   name="";
   age=0;
   seatNo=0;
   destination="";
}
CTrainTicket::~CTrainTicket(){}
void CTrainTicket::getData()
{
   cout<<"Name : ";
   cin>>name;
   cout<<"Age : ";
   cin>>age;
   cout<<"Destination : ";
   cin>>destination;
   cout<<"Seat No. : ";
   cin>>seatNo;
}
void CTrainTicket::displayData(int s)
{
   cout<<s<<"\t|\t"<<name<<"\t\t|\t"<<age<<"\t|\t"<<destination<<"\t\t|\t"<<seatNo<<endl;
}

//CAStack..........
CAStack::CAStack()
{
   CTrainTicket t;
   top=-1;
   capacity=10;
   stackarr = new CTrainTicket[capacity];
   for(int i=0;i<capacity;i++)
   {
      stackarr[i]=t;
   }
}
CAStack::~CAStack()
{
   delete[] stackarr;
}
int CAStack::isFull()
{
   if(top+1==capacity)
      return 1;
   else
      return 0;
}
int CAStack::isEmpty()
{
   if(top==-1)
      return 1;
   else
      return 0;
}
int CAStack::push(CTrainTicket t)
{
   if(isFull())
      return -1;
   else
   {
      top++;
      stackarr[top]=t;
      return 1;
   }
}
int CAStack::display()
{
   if(isEmpty())
      return -1;
   else
   {
      cout<<"SI.No.\t|\tNAME\t\t|\tAGE\t|\tDESTINATION\t|\tSEAT NO.\n";
      cout<<"-----------------------------------------------------------------------------------------\n";
      for(int i=top;i>=0;i--)
      {
         stackarr[i].displayData(i+1);
      }
      return 1;
   }
}
int CAStack::pop()
{
   if(isEmpty())
      return -1;
   else
   {

      cout<<"SI.No.\t|\tNAME\t\t|\tAGE\t|\tDESTINATION\t|\tSEAT NO.\n";
      cout<<"-----------------------------------------------------------------------------------------\n";
      stackarr[top].displayData(top+1);
      top--;
      return 0;
   }
}
int CAStack::size()
{
   if(isEmpty())
      return -1;
   else
      return top+1;
}
int CAStack::makeStackEmpty()
{
   if(isEmpty())
      return -1;
   else
   {
      while(!isEmpty())
      {
         top--;
         //pop();
         //cout<<"\n";
      }
      return 1;
   }
}
int CAStack::peek()
{
   if(isEmpty())
      return -1;
   else
   {
      cout<<"SI.No.\t|\tNAME\t\t|\tAGE\t|\tDESTINATION\t|\tSEAT NO.\n";
      cout<<"-----------------------------------------------------------------------------------------\n";
      stackarr[top].displayData(top+1);
      return 1;
   }
}
int main()
{
   int ch;
   CAStack obj;
   CTrainTicket t;
   cout<<"   ________________________________________________\n";
   cout<<"   |            Stack ADT Using Array             |\n";
   cout<<"   |______________________________________________|\n";
   cout<<"   ************************************************\n";
   cout<<"    *     1.Check Full.                          *\n";
   cout<<"    *     2.Display Stack.                       *\n";
   cout<<"    *     3.Check Empty.                         *\n";
   cout<<"    *     4.Size of the Stack.                   *\n";
   cout<<"    *     5.Push.                                *\n";
   cout<<"    *     6.Peek.                                *\n";
   cout<<"    *     7.Pop.                                 *\n";
   cout<<"    *     8.Make Stack Empty.                    *\n";
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
            int a=obj.isFull();
            if(a==0)
               cout<<"Stack is Not Full. !\n";
            else
               cout<<"Stack is Full..!\n";
            break;
         }
         case 2:
         {
            int a=obj.display();
            if(a==-1)
            {
               cout<<"Stack Is Empty..!\n";
            }
            break;
         }
         case 3:
         {
            int a=obj.isEmpty();
            if(a==1)
               cout<<"Stack is Empty..!\n";
            else
               cout<<"Stack is Not Empty..!\n";
            break;
         }
         case 4:
         {
            int a=obj.size();
            if(a==-1)
               cout<<"Stack is Empty..!\n";
            else
               cout<<"Size : "<<a<<endl;
            break;
         }
         case 5:
         {
            t.getData();
            int a=obj.push(t);
            if(a==-1)
               cout<<"Stack Full Can`t insert..!\n";
            break;
         }
         case 6:
         {
            int a=obj.peek();
            if(a==-1)
               cout<<"Stack is Empty..!\n";
            break;
         }
         case 7:
         {
            int a=obj.pop();
            if(a==-1)
               cout<<"Stack is Empty..!\n";
            break;
         }
         case 8:
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
