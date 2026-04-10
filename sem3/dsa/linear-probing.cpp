#include<iostream>
using namespace std;
class CTrainTicket
{
        friend class CLinearProbing;
        private:
                int seatNo;
                string name;
                int age;
        public:
                CTrainTicket(){seatNo=-1;}
                ~CTrainTicket(){}
                void get() {
                        cout<<"Enter seatNo, name and age: ";
                        cin>>seatNo>>name>>age;
                }
                int getseatNo(){return seatNo;}
                void display(int i)
                {
                        cout<<"|"<<i<<"\t\t|"<<seatNo<<"\t\t|"<<name<<"\t\t|"<<age<<"\t|\n";
                }
};
class CLinearProbing
{
        private:
                int tableSize;
                int size;
                CTrainTicket *table;
        public:
                CLinearProbing(int);
                ~CLinearProbing();
                int insert(CTrainTicket);
                int deleteTicket(int);
                int search(int);
                void display();
                int isFull();
                int isEmpty();
};

CLinearProbing::CLinearProbing(int t)
{
        tableSize = t;
        size = 0;
        table = new CTrainTicket[tableSize];
}
CLinearProbing::~CLinearProbing()
{
        tableSize = 0;
        size = 0;
        delete[] table;
        table = NULL;
}
int CLinearProbing::isFull()
{
        if(size == tableSize)
                return 1;
        else
                return 0;
}
int CLinearProbing::isEmpty()
{
        if( size == 0)
                return 1;
        else
                return 0;
}
int CLinearProbing::insert(CTrainTicket s)
{
        if(isFull()) { return -2;}
        int i,bucketId;
        int K = s.getseatNo();
        for(i=0;i<tableSize;i++)
        {
                bucketId = ((K%tableSize) + i)%tableSize; //HashFn.
                if(table[bucketId].getseatNo()==-1) {
                        table[bucketId] = s;
                        size++;
                        return 1; // Insertion successfull
                }
        }
        return -1; //Not possible
}
int CLinearProbing::deleteTicket(int K)//where K is seatNo
{
        if(isEmpty()) { return -2;}
        int i,bucketId;
        for(i=0;i<tableSize;i++)
        {
                bucketId = ((K%tableSize) + i)%tableSize; //HashFn.
                if(table[bucketId].getseatNo()== K) {
                        table[bucketId].seatNo = -1;
                        size--;
                        return 1; // deletion successfull
                }
        }
        return -1; //Not possible. Element not found
}
int CLinearProbing::search(int K)//where K is seatNo
{
        if(isEmpty()) { return -2;}
        int i,bucketId;
        for(i=0;i<tableSize;i++)
        {

                bucketId = ((K%tableSize) + i)%tableSize; //HashFn.
                if(table[bucketId].getseatNo()== K) {

                cout<<"|=======================================================|\n";
                cout<<"| Bucket ID \t| SeatNo. \t| Name \t\t| Age \t|\n";
                cout<<"|=======================================================|\n";
                        table[bucketId].display(bucketId);
                        return 1; // search successfull
                }
        }
        return -1; //Not possible. Element not found
}
void CLinearProbing::display()
{
        cout<<"|=======================================================|\n";
        cout<<"| Bucket ID \t| SeatNo. \t| Name \t\t| Age\t|\n";
        cout<<"|=======================================================|\n";
        for (int i=0;i<tableSize;i++)
        {
                if(table[i].seatNo != -1)
                {
                   table[i].display(i);//Student class display will be called
                }
                else
                {
                   cout<<"|"<<i<<"\t\t|Empty\t\t|Empty\t\t|Empty\t|\n";
                }
        }
}

int main()
{
    CTrainTicket data;
    int size;
    cout<<"Enter the Size of the Table : ";
    cin>>size;
    CLinearProbing obj(size);
    int ch,k;
    cout << "   ________________________________________________\n";
    cout << "   |              Linear Probing                  |\n";
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
           if(a == 1)
              cout<<"Table is Full..!\n";
           else
              cout<<"Not Full..!\n";
           break;
        }
        case 2:
        {
           int a = obj.isEmpty();
           if(a == 1)
              cout<<"Table is Empty..!\n";
           else
              cout<<"Not Empty..!\n";
            break;
        }
        case 3:
        {
           data.get();
           int a = obj.insert(data);
           if(a == -1)
              cout<<"Can't insert..!\n";
           else if(a == -2)
              cout<<"Table is Full..!\n";
           break;
        }
        case 4:
        {
           cout<<"Enter the Seat No. to delete Ticket : ";
           cin>>k;
           int a = obj.deleteTicket(k);
           if(a==-1)
              cout<<"Deletion Not Possible..!\n";
           else
              cout<<"Deleted..!\n";
            break;
        }
        case 5:
        {
           obj.display();
           break;
        }
        case 6:
        {
           cout<<"Enter the Seat No. to Search : ";
           cin>>k;
           int a = obj.search(k);
           if(a == -2)
              cout<<"Table is Empty..!\n";
           else if(a == -1)
              cout<<"Seat No. Not Found..!\n";
           else
              cout<<"Found..!\n";
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