#include<iostream>
using namespace std;
class CAList
{
   public:
      CAList();
      CAList(int *,int ,int );
      int display();
      int insertAtFirst(int);
      int insertByIndex(int,int);
      int insertByPosition(int,int);
      int insertAtLast(int);
      int deleteAtFirst();
      int deleteAtLast();
      int deleteByIndex(int);
      int deleteByPosition(int);
      int deleteByElement(int);
      int replaceByPosition(int,int);
      int emptyList();
      int insertAtMiddle(int);
      int insertBeforeElement(int ,int);
      int sortElements();
      int getElementByPosition(int);
      int search(int );
      int length();
      int isFull();
      int isEmpty();
      void createList();
   private:
      int *arr;
      int capacity;
      int size;
};
CAList::CAList()
{
   size=0;
   capacity=5;
   arr=new int[5];
   for(int i=0;i<capacity;i++)
   {
      arr[i]=-1;
   }
}
//Parametric Constructor
CAList::CAList(int *a,int c,int s)
{
   size=s;
   capacity=c;
   arr=new int[capacity];
   for(int i=0;i<size;i++)
   {
      arr[i]=a[i];
   }
   for(int i=s;i<capacity;i++)
   {
      arr[i]=-1;
   }
}
//Display list
int CAList::display()
{
   if(isEmpty())
   {
      return -1;
   }
   else
   {
      for(int i=0;i<size;i++)
      {
         cout<<arr[i]<<"\t";
      }
      cout<<endl;
      return 1;
   }
}
int CAList::isFull()
{
   if(size==capacity)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int CAList::isEmpty()
{
   if(size==0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int CAList::length()
{
   return size;
}
int CAList::insertAtFirst(int elt)
{
   if(isFull())
      return -1;
   else if(isEmpty())
   {
      arr[0]=elt;
      size++;
      return 1;
   }
   else
   {
      for(int i=size;i>0;i--)
      {
         arr[i]=arr[i-1];
      }
      arr[0]=elt;
      size++;
      return 2;
   }
}
int CAList::insertByPosition(int pos,int elt)
{
   if(isFull())
      return -1;
   else if (isEmpty() && pos==1)
   {
      arr[0]=elt;
      size++;
      return 1;
   }
   else if(pos<=0 || pos>size+1)
   {
     return -3;
   }
   else
   {
      for(int i=size;i>pos-1;i--)
      {
         arr[i]=arr[i-1];
      }
      arr[pos-1]=elt;
      size++;
      return 2;
   }
}
int CAList::insertByIndex(int index,int elt)
{
   if(isFull())
      return -1;
   else if (isEmpty() && index==0)
   {
      arr[0]=elt;
      size++;
      return 1;
   }
   else if(index < 0 || index > size)
   {
      return -3;
   }
   else
   {
      for(int i=size ; i > index ;i--)
      {
         arr[i]=arr[i-1];
      }
      arr[index]=elt;
      size++;
      return 2;
   }
}
int CAList::insertAtLast(int elt)
{
   if(isFull())
   {
      return -1;
   }
   else if(isEmpty())
   {
      arr[0]=elt;
      size++;
      return 1;
   }
   else
   {
      arr[size]=elt;
      size++;
      return 2;
   }
}
int CAList::search(int elt)
{
   if(isEmpty())
      return -2;
   else
   {
      for(int i=0;i<size;i++)
      {
         if(arr[i]==elt)
         {
            return i+1;
         }
      }
      return -3;
   }
}
int CAList::deleteAtFirst()
{
   if(isEmpty())
   {
      return -2;
   }
   else
   {
      for(int i=0;i<size;i++)
      {
         arr[i]=arr[i+1];
      }
      size--;
      return 1;
   }
}
int CAList::deleteAtLast()
{
   if(isEmpty())
      return -2;
   else
   {
      arr[size-1]=-1;
      size--;
      return 1;
   }
}
int CAList::deleteByIndex(int index)
{
   if(index < 0 || index > size-1)
   {
      return -3;
   }
   else if(isEmpty())
   {
      return -2;
   }
   else if(isFull())
   {
      for(int i=index;i<size-1;i++)
      {
         arr[i]=arr[i+1];
         arr[size]=-1;
      }
      size--;
      return 1;
   }
   else
   {
      for(int i=index;i<size;i++)
      {
         arr[i]=arr[i+1];

      }
      size--;
      return 2;
   }
}

int CAList::deleteByPosition(int pos)
{
   if(pos < 1 || pos > size)
   {
      return -3;
   }
   else if(isEmpty())
      return -2;
   else
   {
      for(int i=pos-1;i<size;i++)
      {
         arr[i]=arr[i+1];
      }
      arr[size-1]=-1;
      size--;
      return 1;
   }
}
int CAList::deleteByElement(int elt)
{
   if(isEmpty())
   {
      return -2;
   }
   else
   {
      int pos = search(elt);
      if(pos==-3)
      {
         return -3;
      }
      else
      {
         deleteByPosition(pos);
         return 1;
      }
   }
}
int CAList::replaceByPosition(int pos,int elt)
{
   if(pos > size || pos < 1)
      return -3;
   else if(isEmpty())
   {
      return -2;
   }
   else
   {
      arr[pos-1]=elt;
      return 1;
   }
}
int CAList::getElementByPosition(int pos)
{
   if(pos<1 || pos> size)
      return -3;
   else if(isEmpty())
   {
      return -2;
   }
   else
   {
      return arr[pos-1];
   }
}
int CAList::emptyList()
{
   if(isEmpty())
      return -1;
   else
   {
      for(int i=0;i<size;i++)
      {
         arr[i]=-1;
      }
      size=0;
      return 2;
   }
}
int CAList::insertAtMiddle(int elt)
{
   if(isFull())
      return -1;
   else if(isEmpty())
   {
      arr[0]=elt;
      size++;
      return 1;
   }
   else
   {
      int pos=(size/2)+1;
      insertByPosition(pos,elt);
      return 2;
   }
}
int CAList::insertBeforeElement(int elt1,int elt)
{
   if(isFull())
   {
      return -1;
   }
   else
   {
      int pos=search(elt1);
      if(pos == -2)
         return -2;
      else if(pos == -3)
         return -3;
      else
      {
         insertByPosition(pos,elt);
         return 1;
      }
   }
}
int CAList::sortElements()
{
   if(isEmpty())
      return -2;
   else
   {
      for(int i=0;i<size-1;i++)
      {
         for(int j=i+1;j<size;j++)
         {
            if(arr[i] > arr[j])
            {
               int temp=arr[j];
               arr[j]=arr[i];
               arr[i]=temp;
            }
         }
      }
      return 1;
   }
}
int main()
{
   int *a;
   int s,c,pos,index;
   int ch,elt,elt1;
   CAList obj;
   cout<<"   ______________________________\n";
   cout<<"   |    List ADT Using Arrays |\n";
   cout<<"   |____________________________|\n";
   cout<<"   ******************************\n";
   cout<<"   * 1.Display List           *\n";
   cout<<"   * 2.Check Full             *\n";
   cout<<"   * 3.Check Empty            *\n";
   cout<<"   * 4.Length of the list.    *\n";
   cout<<"   * 5.Insert at first                *\n";
   cout<<"   * 6.Insert By Position     *\n";
   cout<<"   * 7.Insert By Index                *\n";
   cout<<"   * 8.Insert at Last         *\n";
   cout<<"   * 9.Search (returns position)*\n";
   cout<<"   * 10.Delete at First               *\n";
   cout<<"   * 11.Delete At Last                *\n";
   cout<<"   * 12.Delete By position    *\n";
   cout<<"   * 13.Delete By index               *\n";
   cout<<"   * 14.Delete By Element     *\n";
   cout<<"   * 15.Replace by position   *\n";
   cout<<"   * 16.Get element By Position       *\n";
   cout<<"   * 17.Empty the List                *\n";
   cout<<"   * 18.Insert Before Element *\n";
   cout<<"   * 19.Insert At Middle      *\n";
   cout<<"   * 20.Sort Elements         *\n";
   cout<<"   ******************************\n";
   cout<<"   * 0. Exit!                 *\n";
   cout<<"   ******************************\n\n";
   do
   {
      cout<<"\n\tEnter the choice : ";
      cin>>ch;
      cout<<endl;
      switch(ch)
      {
         case 1:
         {
            int a=obj.display();
            if(a==-1)
            {
               cout<<"List is Empty!\n";
            }
            break;
         }
         case 2:
         {
            int a= obj.isFull();
            if(a)
            {
               cout<<"List is Full\n";
            }
            else
            {
               cout<<"List is Not Full\n";
            }
            break;
         }
         case 3:
         {
            int a=obj.isEmpty();
            if (a)
            {
               cout<<"List is Empty\n";
            }
            else
               cout<<"List is Not Empty\n";
            break;
         }
         case 4:
         {
            cout<<"Length is "<<obj.length();
            cout<<endl;
            break;
         }
         case 5:
         {
            cout<<"Enter the element : ";
            cin>>elt;
            int a=obj.insertAtFirst(elt);
            if(a==-1)
            {
               cout<<"List is FULL! Can't Insert\n";
            }
            else
               cout<<"Inserted..!\n";
            break;
         }
         case 6:
         {
            cout<<"Element to insert : ";
            cin>>elt;
            cout<<"Position to insert : ";
            cin>>pos;
            int a=obj.insertByPosition(pos,elt);
            if(a==-1)
            {
               cout<<"List is FULL! Can't Insert"<<endl;
            }
            else
            {
               if(a==-3)
               {
                  cout<<"Position out of Length!\n"<<endl;
               }
               else
               {
                  cout<<elt<<" Added to the position "<<pos<<endl;
               }
            }
            break;
         }
        case 7:
        {
           cout<<"Element : ";
           cin>>elt;
           cout<<"Index : ";
           cin>>index;
           int a=obj.insertByIndex(index,elt);
           if(a==-1)
           {
              cout<<"List is FULL! Can't insert!"<<endl;
           }

           else
           {
              if(a==-3)
              {
                 cout<<"Index Out of range!"<<endl;
              }
              else
                 cout<<elt<<" Added to the Index "<<index<<endl;
           }
           break;
        }
        case 8:
        {
           cout<<"Enter the element to insert At Last : ";
           cin>>elt;
           int a=obj.insertAtLast(elt);
           if(a==-1)
           {
              cout<<"List is Full! Can't Insert\n";
           }
           else if(a==1)
           {
              cout<<"List is Empty! Hence Inserted At First..!\n";
           }
           else
              cout<<"Inserted..!\n";
           break;
        }
        case 9:
        {
           cout<<"Element to Search : ";
           cin>>elt;
           int a=obj.search(elt);
           if(a==-2)
           {
              cout<<"List is empty!!\n";
           }
           else if(a==-3)
           {
              cout<<elt<<" Not Found!! "<<endl;
           }
           else
           {
              cout<<elt<<" Found At the position "<<a;
           }
           break;
        }
        case 10:
        {
           int a=obj.deleteAtFirst();
           if(a==-2)
           {
              cout<<"List is Empty!"<<endl;
           }
           else
              cout<<"First element Deleted..!\n";
           break;
        }
        case 11:
        {
           int a=obj.deleteAtLast();
           if(a==-2)
           {
              cout<<"List is Empty!"<<endl;
           }
           else
              cout<<" Last element Deleted..!\n";
           break;
        }
        case 12:
        {
           cout<<"Position to Delete : ";
           cin>>pos;
           int a=obj.deleteByPosition(pos);
           if(a==-2)
           {
              cout<<"List is Empty..!\n";
           }
           else if(a==-3)
           {
              cout<<"Position Out of Range...!\n";
           }
           else
           {
              cout<<"Deleted..!\n";
           }
           break;
        }
        case 13:
        {
           cout<<"Index to delete : ";
           cin>>index;
           int a=obj.deleteByIndex(index);
           if(a==-3)
           {
              cout<<"Index out of length!\n";
           }
           else if(a==-2)
           {
              cout<<"List is Empty! Can't Delete!!\n";
           }
           else
              cout<<"Deleted..!\n";
           break;
        }
        case 14:
        {
           cout<<"Enter the Element to delete : ";
           cin>>elt;
           int a=obj.deleteByElement(elt);
           if(a==-2)
           {
              cout<<"List is Empty! Can't delete..!\n";
           }
           else if(a==-3)
           {
              cout<<"Element Not Found!\n";
           }
           else
              cout<<"Deleted..!\n";
           break;
        }
        case 15:
        {
           cout<<"Position to replace : ";
           cin>>pos;
           cout<<"Enter the element to replace : ";
           cin>>elt;
           int a=obj.replaceByPosition(pos,elt);
           if(a==-2)
           {
              cout<<"list is Empty Can't Replace"<<endl;
           }
           else if(a==-3)
           {
              cout<<"position out of Length!\n";
           }
           else
           {
              cout<<"Replaced!\n";
           }
           break;
        }
        case 16:
        {


           cout<<"Position to Retrive the element in list : ";
           cin>>pos;
           int a=obj.getElementByPosition(pos);
           if(a==-2)
           {
              cout<<"List is empty"<<endl;
           }
           else if(a==-3)
           {
              cout<<"Position out of Range!\n";
           }
           else
              cout<<a<<" is At the position "<<pos<<endl;
           break;
        }
        case 17:
        {
           int a=obj.emptyList();
           if(a==-1)
           {
              cout<<"List is Already Empty..!\n";
           }
           else
           {
              cout<<"Successfull..!\n";
           }
           break;
        }
        case 18:
        {
           cout<<"Enter the before Element : ";
           cin>>elt1;
           cout<<"Enter the new element to insert before "<<elt1<<" : ";
           cin>>elt;
           int a=obj.insertBeforeElement(elt1,elt);
           if(a==-2)
              cout<<"List Is Empty!"<<endl;
           else if(a==-3)
           {
              cout<<"Before element Not Found!\n";
           }
           else if(a==-1)
           {
              cout<<"List is Empty! Can't Insert!\n";
           }
           else
           {
              cout<<"Inserted..! \n";
           }
           break;
        }
        case 19:
        {

           cout<<"Element to Insert at Middle : ";
           cin>>elt;
           int a=obj.insertAtMiddle(elt);
           if(a==-1)
           {
              cout<<"List is Full! Can't Insert!"<<endl;
           }
           else if(a==1)
           {
              cout<<"List is Empty Hence Inserted At First ..!\n";
           }
           else
           {
              cout<<"Inserted..!\n";
           }
           break;
        }
        case 20:
        {
           int a=obj.sortElements();
           if(a==-2)
           {
              cout<<"List is Empty! Can't Sort..!"<<endl;
           }
           else
           {
              cout<<"Sorted!\n";
           }
           break;
        }
        case 0:
        {
           break;
        }
        default:
        {
           cout<<"INVALID Choice!! \n\n";
        }



      }//switch

   } while(ch!=0);//while
cout<<"Exited...!\n\n";
return 0;
}//main
