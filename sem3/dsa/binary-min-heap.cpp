#include <iostream>
#include <cmath>
using namespace std;

class CTrainTicket
{
private:
    string name;
    int age;
    string destination;
    int seatNo;

public:
    CTrainTicket();
    ~CTrainTicket();
    CTrainTicket(string, int, string, int);
    void getData();
    void displayData();
    friend class CBHeap;
};

class CBHeap
{
private:
    CTrainTicket *heap;
    int capacity;
    int hSize;

public:
    CBHeap();
    ~CBHeap();
    CBHeap(int);
    int isEmpty();
    int isFull();
    int insert(CTrainTicket);
    int deleteMin();
    int returnMin();
    int increaseKeyBy(int, int);
    int increaseKeyWith(int, int);
    int decreaseKeyBy(int, int);
    int decreaseKeyWith(int, int);
    int buildHeap(CTrainTicket *, int);
    void percolateUp(int);
    void percolateDown(int);
    void displayHeap();
    int getHSize();
    int getCapacity();
    void displaySizeCapacity();
};
CTrainTicket::CTrainTicket()
{
    name = "";
    age = 0;
    destination = "";
    seatNo = 0;
}
CTrainTicket::~CTrainTicket() {}

CTrainTicket::CTrainTicket(string n, int a, string d, int s)
{
    name = n;
    age = a;
    destination = d;
    seatNo = s;
}

void CTrainTicket::getData()
{
    cout << "Name : ";
    cin >> name;
    cout << "Age : ";
    cin >> age;
    while(age < 0)
    {
       cout<<"Enter the Valid Age : ";
       cin>> age;
    }
    cout << "Destination : ";
    cin >> destination;
    cout << "Seat No. : ";
    cin >> seatNo;
}

void CTrainTicket::displayData()
{
    cout << name << "\t|\t" << age << "\t|\t" << destination << "\t\t|\t" << seatNo << endl;
}

CBHeap::CBHeap()
{
    capacity = 0;
    hSize = 0;
    heap = NULL;
}

CBHeap::~CBHeap()
{
    delete[] heap;
    hSize = 0;
}

CBHeap::CBHeap(int h)
{
    hSize = 0;
    capacity = pow(2, h + 1) - 1;
    heap = new CTrainTicket[capacity + 1];
}

void CBHeap::displayHeap()
{
    if (hSize == 0)
    {
        cout << "Heap is Empty!\n";
        return;
    }

    cout << "Name\t|\tAge\t|\tDestination\t|\tSeatNo" << endl;
    cout << "--------------------------------------------------------------\n";
    for (int i = 1; i <= hSize; i++)
        heap[i].displayData();
}

void CBHeap::percolateUp(int index)
{
    CTrainTicket temp = heap[index];
    while (index > 1 && heap[index / 2].age > temp.age)
    {
        heap[index] = heap[index / 2];
        index = index / 2;
    }
    heap[index] = temp;
}

void CBHeap::percolateDown(int index)
{
    int child;
    CTrainTicket temp = heap[index];
    while (2 * index <= hSize)
    {
        child = 2 * index;
        if (child + 1 <= hSize && heap[child + 1].age < heap[child].age)
            child++;
        if (heap[child].age >= temp.age)
            break;
        heap[index] = heap[child];
        index = child;
    }
    heap[index] = temp;
}

int CBHeap::insert(CTrainTicket t)
{
    if (hSize >= capacity)
        return -1;

    hSize++;
    heap[hSize] = t;
    percolateUp(hSize);
    return 1;
}

int CBHeap::deleteMin()
{
    if (hSize == 0)
        return -1;

    heap[1] = heap[hSize];
    hSize--;
    if (hSize > 0)
        percolateDown(1);
    return 1;
}

int CBHeap::returnMin()
{
    if (hSize < 1)
        return -1;

    cout << "Name\t|\tAge\t|\tDestination\t|\tSeatNo" << endl;
    cout << "----------------------------------------------------------\n";
    heap[1].displayData();
    return 1;
}

int CBHeap::increaseKeyBy(int s, int a)
{
    if (hSize < 1)
        return -1;

    for (int i = 1; i <= hSize; i++)
    {
        if (heap[i].seatNo == s)
        {
            if (a <= heap[i].age || a < 0)
                return -2;
            heap[i].age = a;
            percolateDown(i);
            return 1;
        }
    }
    return -3;
}

int CBHeap::increaseKeyWith(int s, int a)
{
    if (hSize < 1)
        return -1;

    for (int i = 1; i <= hSize; i++)
    {
        if (heap[i].seatNo == s)
        {
            heap[i].age += a;
            percolateDown(i);
            return 1;
        }
    }
    return -3;
}

int CBHeap::decreaseKeyBy(int s, int a)
{
    if (hSize < 1)
        return -1;

    for (int i = 1; i <= hSize; i++)
    {
        if (heap[i].seatNo == s)
        {
            if (a >= heap[i].age || a < 0)
                return -2;
            heap[i].age = a;
            percolateUp(i);
            return 1;
        }
    }
    return -3;
}

int CBHeap::decreaseKeyWith(int s, int a)
{
    if (hSize < 1)
        return -1;

    for (int i = 1; i <= hSize; i++)
    {
        if (heap[i].seatNo == s)
        {
            heap[i].age -= a;
            if (heap[i].age < 0)
                heap[i].age = 0;
            percolateUp(i);
            return 1;
        }
    }
    return -3;
}

int CBHeap::buildHeap(CTrainTicket *arr, int n)
{
    if (hSize + n > capacity)
        return -1;

    for (int i = 0; i < n; ++i)
    {
        insert(arr[i]);
    }
    return 1;
}

int CBHeap::getHSize()
{
   return hSize;
}
int CBHeap::getCapacity()
{
   return capacity;
}
void CBHeap::displaySizeCapacity()
{
    cout<<"Size = "<<hSize<<endl;
    cout<<"Capacity = "<<capacity<<endl;
}
int CBHeap::isFull()
{
   if(hSize == capacity)
      return 1;
   else
      return 0;
}
int CBHeap::isEmpty()
{
   if(hSize == 0)
      return 1;
   else
      return 0;

}
int main()
{
    CTrainTicket data,*arr;
    int s, ag, h, ch,n;

    cout << "Height of the Tree : ";
    cin >> h;
    cout << "Capacity : " << pow(2, h + 1) - 1 << endl;
    CBHeap obj(h);

    cout << "   ________________________________________________\n";
    cout << "   |              Priority Queue                  |\n";
    cout << "   |______________________________________________|\n";
    cout << "   ************************************************\n";
    cout << "    *     1. Insertion                           *\n";
    cout << "    *     2. Display Heap                        *\n";
    cout << "    *     3. Return Min                          *\n";
    cout << "    *     4. Increase Key with                   *\n";
    cout << "    *     5. Increase Key By                     *\n";
    cout << "    *     6. Decrease Key With                   *\n";
    cout << "    *     7. Decrease Key By                     *\n";
    cout << "    *     8. Delete Minimum                      *\n";
    cout << "    *     9. Build Heap                          *\n";
    cout << "    *     10. Display Size and capacity of heap  *\n";
    cout << "    *     11.IsEmpty                             *\n";
    cout << "    *     12. IsFull                             *\n";
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
            data.getData();
            int a = obj.insert(data);
            if (a == -1)
                cout << "Heap is Full..!\n";
            else
                cout << "Inserted..!\n";
            break;
        }
        case 2:
        {
            obj.displayHeap();
            break;
        }
        case 3:
        {
            int a = obj.returnMin();
            if (a == -1)
                cout << "Heap is Empty..!\n";
            break;
        }
        case 4:
        {
            cout << "Seat No. to increase Age (set new age): ";
            cin >> s;
            cout << "Enter the New Age : ";
            cin >> ag;
            int a = obj.increaseKeyBy(s, ag);
            if (a == -1)
                cout << "Heap is Empty..!\n";
            else if (a == -2)
                cout << "Invalid Key..!\n\tNew age must be greater than old age.\n";
            else if (a == -3)
                cout << "Seat Not Found..!\n";
            else
                cout << "Done..!\n";
            break;
        }
        case 5:
        {
            cout << "Seat No. to increase Age by +value: ";
            cin >> s;
            cout << "Increase Age By : ";
            cin >> ag;
            int a = obj.increaseKeyWith(s, ag);
            if (a == -1)
                cout << "Heap is Empty..!\n";
            else if (a == -3)
                cout << "Seat Not Found..!\n";
            else
                cout << "Done..!\n";
            break;
        }
        case 6:
        {
            cout << "Seat No. to decrease Age (set new age): ";
            cin >> s;
            cout << "Enter the New Age : ";
            cin >> ag;
            int a = obj.decreaseKeyBy(s, ag);
            if (a == -1)
                cout << "Heap is Empty..!\n";
            else if (a == -2)
                cout << "Invalid Key..!\n\tNew age must be less than old age.\n";
            else if (a == -3)
                cout << "Seat Not Found..!\n";
            else
                cout << "Done..!\n";
            break;
        }
        case 7:
        {
            cout << "Seat No. to decrease Age by -value: ";
            cin >> s;
            cout << "Decrease Age By : ";
            cin >> ag;

           /* while(ag < 0)
            {
               cout<"Enter the Valid Age : ";
               cin>> ag;
            }*/
            int a = obj.decreaseKeyWith(s, ag);
            if (a == -1)
                cout << "Heap is Empty..!\n";
            else if (a == -3)
                cout << "Seat Not Found..!\n";
            else
                cout << "Done..!\n";
            break;
        }
        case 8:
        {
            int a = obj.deleteMin();
            if (a == -1)
                cout << "Heap is Empty..!\n";
            else
                cout << "Deleted minimum..!\n";
            break;
        }
        case 9:
        {
         cout<<"Enter the No. of persons to Build : ";
         cin>>n;
         if((n + obj.getHSize()) > obj.getCapacity())
         {
            cout<<"Maximum Capacity reached..!\n\tOperation Cancelled"<<endl;
            break;
         }
         arr = new CTrainTicket[n];
         for(int i=0;i<n;i++)
         {
            cout<<"\n\tPassenger :"<<1+i+obj.getHSize()<<endl<<endl;
            arr[i].getData();
         }
         int a = obj.buildHeap(arr,n);
         break;
        }
        case 10:
        {
            obj.displaySizeCapacity();
            break;
        }
        case 11:
        {
           int a=obj.isEmpty();
           if(a== 1)
              cout<<"Heap is Empty..!\n";
           else
              cout<<"Heap is Not Empty..!\n";
           break;
        }
        case 12:
        {
           int a= obj.isFull();
           if(a==1)
              cout<<"Heap is Full..!\n";
           else
              cout<<"heap is Not full..!";
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