#include<iostream>
using namespace std;
/*class CTrainTicket;
class CLList;
class CNode;*/
class CTrainTicket
{
   private:
      string name;
      string destination;
      int age;
   public:
      CTrainTicket(string ,int ,string ,int );
      CTrainTicket();
      void getData();
      void displayData(int);
      int seatNo;
};
class CNode
{
   private:
      CTrainTicket data;
      CNode *next;
      friend class CLList;
   public:
      CNode();
      CNode(CTrainTicket,CNode *);
      ~CNode();
      void get();
      void display(int);
};

class CLList
{
   private:
      CNode *first;
   public:
      CLList();
      int displayList();
      int displayLength();
      int isEmpty();
      int insertAtFirst(CNode*);
      int insertByPosition(int,CNode*);
      int insertAtLast(CNode *);
      int deleteAtFirst();
      int deleteAtLast();
      int deleteByPosition(int);
      int makeListEmpty();
      int searchBySeatNo(int);
      int deleteBySeatNo(int);
      int replaceSeatDetails(int);
      int getSeatDetails(int);
      int sort();
      int insertBeforeSeatNo(int,CNode*);
      //int displayReverse();
};
//CTrainTicket
CTrainTicket :: CTrainTicket()
{
   name="UNKNOWN";
   age = 0;
   destination="UNKNOWN";
   seatNo=0;
}
CTrainTicket::CTrainTicket(string n,int a,string des,int s)
{
   name=n;
   age=a;
   destination=des;
   seatNo=s;
}
void CTrainTicket::getData()
{
   cout<<"\n_____FILL THE DETAILS_____\n";
   cout<<"Name : ";
   cin>>name;
   cout<<"Age : ";
   cin>>age;
   cout<<"Destination : ";
   cin>>destination;
   cout<<"Seat No.  : ";
   cin>>seatNo;
}
void CTrainTicket::displayData(int n)
{
   cout<<n<<".\t|\t"<<name<<"\t|\t"<<age<<"\t|\t"<<destination<<"\t\t|\t"<<seatNo<<endl;
}
//CNode
CNode :: CNode()
{
   next=NULL;
}
CNode::CNode(CTrainTicket t,CNode *n)
{
   data=t;
   next=n;
}
CNode :: ~CNode()
{
   next=NULL;
}
void CNode :: get()
{
   data.getData();
}
void CNode::display(int n)
{
   //cout<<"SI No.\t\tName\t\tAge\t\tDestination\t\tSeatNo.\n";
   data.displayData(n);
}

//CLList
CLList :: CLList()
{
   first=NULL;
}
int CLList::isEmpty()
{
   if(first==NULL)
      return 1;
   else
      return 0;
}
int CLList:: displayLength()
{
   int count=0;
   CNode *temp=first;
   if(isEmpty())
      return -1;
   else
   {
      while(temp!=NULL)
      {
         count++;
         temp=temp->next;
      }
      return count;
   }

}
int CLList::displayList()
{
   CNode *temp=first;

   if(temp==NULL)
      return -1;
   else
   {
      cout<<"SI No.\t|\tName\t|\tAge\t|\tDestination\t|\tSeatNo.\n";
      cout<<"----------------------------------------------------------------------------------------\n";
      int count=0;
      while(temp!=NULL)
      {
         count++;
         temp->display(count);
         temp=temp->next;
      }
      return 1;
   }
}
int CLList::insertAtFirst(CNode *newNode)
{
   if(isEmpty())
   {
      first=newNode;
      return 1;
   }
   else
   {
      newNode->next=first;
      first=newNode;
      return 2;
   }
}
int CLList::insertByPosition(int pos,CNode* n)  //Action needed
{
   if(isEmpty())
   {
      insertAtFirst(n);
      return 1;
   }
   else if(pos==1)
   {
      insertAtFirst(n);
      return 2;
   }
   else
   {
      int count = 1;
      CNode *temp = first,*prev;
      while(temp != NULL && count < (pos-1))
      {
          temp = temp->next;
          count ++;
      }
      if(count == (pos-1) && temp!=NULL)
      {
         prev=temp;
         temp=temp->next;
         prev->next=n;
         n->next=temp;
         //delete temp;
         return 3;
      }
      else
      {
         return -2;
      }
   }
}
int CLList::insertAtLast(CNode *n)
{
   if(isEmpty())
   {
      first = n;
      return 1;
   }
   else
   {
      CNode *temp=first;
      while(temp->next!=NULL)
      {
         temp=temp->next;
      }
      temp->next=n;
      return 2;
   }
}
int CLList::deleteAtFirst()
{
   if(isEmpty())
      return -1;
   else
   {
      CNode* temp=first;
      first=first->next;
      delete temp;
      temp = NULL;
      return 2;
   }
}
int CLList::deleteAtLast()
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      CNode *temp=first;
      CNode *prev=NULL;
      while(temp->next!=NULL)
      {
         prev=temp;
         temp=temp->next;
      }
      prev->next=NULL;
      temp = NULL;
      delete temp;
      return 1;
   }
}
int CLList::deleteByPosition(int pos)
{
   if(isEmpty())
   {
      return -1;
   }
   else if(pos==1)
   {
      deleteAtFirst();
      return 1;
   }
   else
   {
      CNode* prev=NULL;
      CNode* temp=first;
      int count=1;
      while(temp!=NULL && count<(pos-1))
      {
         temp=temp->next;
         count++;
      }
      if(count==(pos-1) && temp!=NULL)
      {
         prev=temp;
         temp=temp->next;
         //count++;
         prev->next=temp->next;
         delete temp;
         temp=NULL;
         return 1;
      }
      else
         return -2;
   }
}
int CLList::makeListEmpty()
{
   if(isEmpty())
      return -1;
   else
   {
      CNode *temp=first;
      while(temp!=NULL)
      {
         CNode *d=temp;
         temp=temp->next;
         delete d;
      }
      first=NULL;
      return 1;
   }
}
int CLList::searchBySeatNo(int s)
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      CNode *temp=first;
      int count=1;
      while(temp!=NULL)
      {
         if(temp->data.seatNo==s)
         {
            return count;
         }
         else
         {
            count++;
            temp=temp->next;
         }
      }
      return -2;
   }
}
int CLList::deleteBySeatNo(int s)//works after deleteByPositon
{
   if(isEmpty())
      return -1;
   else
   {
      int a=deleteByPosition(searchBySeatNo(s));
      return a;
   }
}
int CLList::replaceSeatDetails(int pos)
{
   if(isEmpty())
      return -1;
   else
   {
      CNode *temp=first;
      int count=1;
      while(temp!=NULL && count<pos)
      {
         temp=temp->next;
         count++;
      }
      if(temp!=NULL && pos==count)
      {
         temp->get();
         return 1;
      }
      else
         return -2;
   }
}

int CLList::getSeatDetails(int pos)
{
   if(isEmpty())
      return -1;
   else
   {
      CNode *temp=first;
      int count=1;
      while(temp!=NULL && count<pos)
      {
         temp=temp->next;
         count++;
      }
      if(temp!=NULL && pos==count)
      {
         temp->display(pos);
         return 1;
      }
      else
         return -2;
   }
}
int CLList::sort()
{
   if(isEmpty())
      return -1;
   else
   {
      CNode *temp=first,*prev;
      CTrainTicket t;
      while(temp->next!=NULL)
      {
         prev=temp;
         temp=temp->next;
         if(prev->data.seatNo > temp->data.seatNo)
         {
            t=prev->data;
            prev->data=temp->data;
            temp->data=t;
         }
      }
      return 1;
   }
}
/*int CLList::displayReverse()
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      CNode *temp=first;
      CLList *rev;
      //CTrainTicket a[20];
      ////CNode *t;
      while(temp->next!=NULL)
      {
         temp=temp->next;
         //CNode *n=new CNode(temp->data,temp)
         rev->insertAtFirst(temp);
         rev->displayList();
      }
      return 1;
   }
}*/
int CLList::insertBeforeSeatNo(int s,CNode *n)
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      int a=insertByPosition((searchBySeatNo(s)),n);
      if(a==-2)
      {
        return -2;
      }
      else
      {
         return 1;
      }
   }
}
int main()
{
   int s,c,pos,index;
   int ch,elt,elt1;
   CLList obj;
   CTrainTicket t;
   cout<<"   _______________________________________________\n";
   cout<<"   |    List ADT Using Linked List               |\n";
   cout<<"   |_____________________________________________|\n";
   cout<<"   ***********************************************\n";
   cout<<"    * 1.Display List                            *\n";
   cout<<"    * 2.Check Empty                             *\n";
   cout<<"    * 3.Length of the list.                     *\n";
   cout<<"    * 4.Insert at first                         *\n";
   cout<<"    * 5.Insert By Position                      *\n";
   cout<<"    * 6.Insert at Last                          *\n";
   cout<<"    * 7.Delete at First                         *\n";
   cout<<"    * 8.Delete At Last                          *\n";
   cout<<"    * 9.Delete By position                      *\n";
   cout<<"    * 10.Delete By SeatNo.                      *\n";
   cout<<"    * 11.Search By seat No.(returns position).  *\n";
   cout<<"    * 12.Replace by position                    *\n";
   cout<<"    * 13.Get element By Position                *\n";
   cout<<"    * 14.Empty the List                         *\n";
   cout<<"    * 15.Sort                                   *\n";
   cout<<"    * 16.insertBeforeSeatNo.                    *\n";
   cout<<"   ***********************************************\n";
   cout<<"   * 0. Exit!                                    *\n";
   cout<<"   ***********************************************\n\n";
   do
   {
      cout<<"\n\tEnter the choice : ";
      cin>>ch;
      cout<<endl;
      switch(ch)
      {
         case 1:
         {
            int a=obj.displayList();
            if(a==-1)
            {
               cout<<"List Is Empty..!\n";
            }
            break;
         }
         case 2:
         {
            int a=obj.isEmpty();
            if(a==1)
               cout<<"List is Empty..!\n";
            else
               cout<<"List is Not Empty..!\n";
            break;

         }
         case 3:
         {
            int a=obj.displayLength();
            if(a==-1)
            {
               cout<<"List is Empty..!\n";
            }
            else
            {
               cout<<"Length is : "<<a<<endl;
            }
            break;
         }
         case 4:
         {
            t.getData();
            CNode *n=new CNode(t,NULL);
            int a=obj.insertAtFirst(n);
            if(a==1 || a==2)
            {
               cout<<"Inserted..!\n";
            }
            break;
         }
         case 5:
         {
            cout<<"Enter the Position to insert :";
            cin>>pos;
            t.getData();
            CNode* newNode=new CNode(t,NULL);
            int a=obj.insertByPosition(pos,newNode);
            if(a==1)
            {
               cout<<"Inserted At First..!\n";
            }
            else if(a==2)
               cout<<"inserted at position "<<pos<<endl;
            else if(a==-2)
            {
               cout<<"Position out of range..!\n ";
            }
            else
            {
               cout<<"Inserted At Position "<<pos<<endl;
            }
            break;
         }
         case 6:
         {
            t.getData();
            CNode *n=new CNode(t,NULL);
            int a=obj.insertAtLast(n);
            if(a==1)
            {
               cout<<"List is Empty ... Inerted At First..!\n";
            }
            else
            {
               cout<<"Inserted At Last..!\n";
            }
            break;
         }
         case 7:
         {
            int a=obj.deleteAtFirst();
            if(a==-1)
            {
               cout<<"List is Empty..!\n";
            }
            else
            {
               cout<<"Deleted..!\n";
            }
            break;
         }
         case 8:
         {
            int a=obj.deleteAtLast();
            if(a==-1)
            {
               cout<<"List is Empty..!\n";
            }
            else
            {
               cout<<"Deleted..!\n";
            }
            break;
         }
         case 9:
         {
            cout<<"Enter the Position to delete : ";
            cin>>pos;
            int a=obj.deleteByPosition(pos);
            if(a==-2)
            {
               cout<<"Position Out of Index..!\n";
            }
            else if (a==-1)
            {
               cout<<"List is Empty..!\n";
            }
            else
            {
               cout<<"Deleted.. !\n";
            }
            break;
         }
         case 10:
         {
            cout<<"SeatNo. to delete : ";
            cin>>s;
            if(s<0)
            {
               cout<<"Invalid Seat No.\n";
               break;
            }
            int a=obj.deleteBySeatNo(s);
            if(a==-1)
               cout<<"List is Empty..!";
            else if(a==-2)
               cout<<"Seat is already Free..!\n";
            else
               cout<<"Seat is Deleted..!\n";
            break;

         }
         case 11:
         {
            cout<<"Seat No. to search : ";
            cin>>s;
            int a=obj.searchBySeatNo(s);
            if(a==-1)
            {
               cout<<"List is Empty..!\n";
            }
            else if(a==-2)
            {
               cout<<"Seat is Free..!\n";
            }
            else
            {
               cout<<"Seat is Occupied.Detail No."<<a<<endl;
            }
            break;
         }
         case 12:
         {
            cout<<"Enter the position to Replace : ";
            cin>>pos;
            int a = obj.replaceSeatDetails(pos);
            if(pos<=0)
            {
               cout<<"Invalid position !\n";
               break;
            }
            if(a==-2)
            {
               cout<<"Position out of range..!\n";
            }
            else if(a==-1)
            {
               cout<<"List is Empty ..!\n";
            }
            else
               cout<<"Replaced Detail no. "<<pos<<endl;
            break;
         }
         case 13:
         {
            cout<<"Enter the position to Get Details : ";
            cin>>pos;
            int a=obj.getSeatDetails(pos);
            if(pos <=0)
            {
               cout<<"Invalid position..!\n";
               break;
            }
            if(a==-1)
               cout<<"List is Empty..!\n";
            else if(a==-2)
            {
               cout<<"Position out of index..!\n";
            }
            else
            {
               cout<<"";
            }
            break;
         }
         case 14:
         {
            int a=obj.makeListEmpty();
            if(a==-1)
            {
               cout<<"List is Already Empty..!\n";
            }
            else
               cout<<"SuccessFul..!\n";
            break;
         }
         case 15:
         {
            int a=obj.sort();
            if(a==-1)
               cout<<"List is Empty..! Can't Sort!\n";
            else
               cout<<"Successfull..!\n";
            break;
         }
         /*case 16:
         {
            int a=obj.displayReverse();
            if(a==-1)
               cout<<"List is Empty..!\n";
            else
               cout<<"\nReverse order With respect to seat No. :\n";
            break;
         }*/
         case 16:
         {
            cout<<"Enter the SeatNo. : ";
            cin>>s;
            t.getData();
            CNode *n=new CNode(t,NULL);
            int a=obj.insertBeforeSeatNo(s,n);
            if(a==-1)
               cout<<"List is Empty..!";
            else if(a==-2)
               cout<<"Invaid SeatNo. \n";
            break;
         }
      }
   }while(ch!=0);
}
