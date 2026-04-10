#include<iostream>
#include<string>
using namespace std;
class CBST;
class CNode;
class CTrainTicket
{
    public:
        CTrainTicket();
        CTrainTicket(string,int,string,int );
        CTrainTicket(const CTrainTicket&);
        ~CTrainTicket();
        void displayData();
    private:
        string name;
        int age;
        string destination;
        int seatNo;
        friend class CNode;
        friend class CBST;
};
class CNode
{
   private:
      CTrainTicket data;
      CNode* left;
      CNode* right;
   public:
      CNode(CTrainTicket);
      ~CNode();
      void display();
      friend class CBST;
};
class CBST
{
   private:
      CNode* root;
   public:
      CBST();
      ~CBST();
      CNode* getRoot();
      void setRoot(CNode* r);
      bool isEmpty();
      bool insert(CNode*,CNode*);
      CNode* deleteElt(CNode*,int,bool&);
      CNode* search(CNode*,int);
      CNode* findMin(CNode*);
      CNode* findMax(CNode*);
      void InOrder(CNode*);
      void PreOrder(CNode*);
      void PostOrder(CNode*);
      int makeTreeEmpty();
};
CTrainTicket::CTrainTicket()
{
    name = "";
    age = 0;
    destination = "";
    seatNo = 0;
}
CTrainTicket::CTrainTicket(string n,int a,string d,int s)
{
    name = n;
    age = a;
    destination = d;
    seatNo= s;
}
CTrainTicket::CTrainTicket(const CTrainTicket &t)
{
    name = t.name;
    age = t.age;
    destination = t.destination;
    seatNo = t.seatNo;
}
CTrainTicket::~CTrainTicket()
{
}
void CTrainTicket::displayData()
{
    cout << name << "\t\t" << age << "\t\t" << destination <<"\t\t\t" <<  seatNo << endl << endl;
}
CNode::CNode(CTrainTicket t)
{
   data = t;
   left = NULL;
   right = NULL;
}
CNode::~CNode()
{
   left = NULL;
   right = NULL;
}
void CNode::display()
{
   data.displayData();
}
CBST::CBST()
{
      root=NULL;
}
CBST::~CBST()
{
      root=NULL;
}
CNode* CBST::getRoot()
{
      return root;
}
void CBST::setRoot(CNode* r)
{
      root=r;
}
bool CBST::isEmpty()
{
        if(root == NULL)
                return true;
        else
                return false;
}
bool CBST::insert(CNode *temp, CNode *newNode)
{
        if(isEmpty())
        {
                root = newNode;
                return true;
        }
        else
        {
                if(temp->data.seatNo > newNode->data.seatNo)
                {
                        if(temp->left == NULL)
                        {
                                temp->left = newNode;
                                return true;
                        }
                        else
                                return insert(temp->left, newNode);
                }
                else if(temp->data.seatNo < newNode->data.seatNo)
                {
                        if(temp->right == NULL)
                        {
                                temp->right = newNode;
                                return true;
                        }
                        else
                                return insert(temp->right, newNode);
                }
                else // Duplicate element insertion not possible
                        return false;
        }
}
CNode* CBST::findMin(CNode *root)
{
        CNode* temp = root;
        while(temp->left != NULL)
        {
                temp = temp->left;
        }
        return temp;
}
CNode* CBST::findMax(CNode *root)
{
        CNode* temp = root;
        while(temp->right != NULL)
        {
                temp = temp->right;
        }
        return temp;
}
CNode* CBST::deleteElt(CNode* temp, int elt,bool &status)
{
    if(temp==NULL) // Element not found
    {
       status=false;
       return NULL;
    }
    else if(elt < temp->data.seatNo)
        temp->left = deleteElt(temp->left, elt,status);
    else if(elt > temp->data.seatNo)
        temp->right = deleteElt(temp->right, elt,status);
    else
    {
        if(temp->left == NULL && temp->right == NULL)  //node has no child
        {
            delete temp;
            temp = NULL;
            status=true;
        }
        else if(temp->left == NULL) // node has only right child
        {
            temp = temp->right;
            status=true;
        }
        else if(temp->right == NULL) // node has only left child
        {
            temp = temp->left;
            status=true;
        }
        else // node has two children
        {
            CNode* min = findMin(temp->right);
            temp->data = min->data;
            temp->right = deleteElt(temp->right, min->data.seatNo,status);
        }
    }
    return temp;
}
CNode* CBST::search(CNode* temp, int elt)
{
        if(temp == NULL || temp->data.seatNo == elt)
        {
                return temp;
        }
        else if(temp->data.seatNo < elt)
        {
                return search(temp->right, elt);
        }
        else if(temp->data.seatNo > elt)
        {
                return search(temp->left, elt);
        }
        else
        {
                return NULL;
        }
}
void CBST::InOrder(CNode *temp)
{
        if(temp != NULL)
        {
                InOrder(temp->left);
                temp->data.displayData();
                InOrder(temp->right);
        }
}
void CBST::PreOrder(CNode *temp)
{
        if(temp != NULL)
        {
                temp->data.displayData();
                PreOrder(temp->left);
                PreOrder(temp->right);
        }
}
void CBST::PostOrder(CNode *temp)
{
        if(temp != NULL)
        {
                PostOrder(temp->left);
                PostOrder(temp->right);
                temp->data.displayData();
        }
}
int CBST::makeTreeEmpty()
{
   if(root==NULL)
      return 0;
   else
   {
      root=NULL;
      delete root;
      return 1;
   }
}
main()
{
        string n,d;
        int s,a,elt;
        CBST b;
        bool ret;
        int i=0,ch;
         cout<<"   ________________________________________________\n";
         cout<<"   |                    BST                       |\n";
         cout<<"   |______________________________________________|\n";
         cout<<"   ************************************************\n";
         cout<<"    *     1.Insertion.                           *\n";
         cout<<"    *     2.Inorder.                             *\n";
         cout<<"    *     3.Preorder.                            *\n";
         cout<<"    *     4.Postorder                            *\n";
         cout<<"    *     5.Delete                               *\n";
         cout<<"    *     6.Search                               *\n";
         cout<<"    *     7.Find Min                             *\n";
         cout<<"    *     8.Find Max.                            *\n";
         cout<<"    *     9.Get root.                            *\n";
         cout<<"   ************************************************\n";
         cout<<"   *        0. Exit!                              *\n";
         cout<<"   ************************************************\n\n";
        do
        {
                cout<<"\n\tEnter your choice: ";
                cin>>ch;
                cout<<endl;
                switch(ch)
                {
                        case 1:
                        {
                                cout << "Enter The passenger Details..."<<endl;
                                cout << "Name : ";
                                cin >> n;
                                cout << "Age : ";
                                cin >> a;
                                cout << "Destination : ";
                                cin >> d;
                                cout << "Seat No. : ";
                                cin >> s;
                                CTrainTicket t(n,a,d,s);
                                CNode *newNode = new CNode(t);
                                ret = b.insert(b.getRoot(),newNode);
                                if(ret)
                                   cout<<"Inserted\n";
                                else
                                   cout<<"Duplicate Seat no. ...!.\n";
                        }
                        break;
                        case 2:
                        {
                                cout<<"InOrder Traversal\n";
                                cout<<"Name.\t\tAge.\t\tDestination.\t\tSeatNo.\n";
                                cout<<"==============================================================\n";
                                b.InOrder(b.getRoot());
                                cout<<"\n";
                                break;
                        }
                        case 3:
                        {
                                cout<<"PreOrder Traversal\n";
                                cout<<"Name.\t\tAge.\t\tDestination.\t\tSeat No.\n";
                                cout<<"===============================================================\n";
                                b.PreOrder(b.getRoot());
                                cout<<"\n";
                                break;
                        }
                        case 4:
                        {
                                cout<<"PostOrder Traversal\n";
                                cout<<"Name.\t\tAge.\t\tDestination.\t\tSeat No.\n";
                                cout<<"================================================================\n";
                                b.PostOrder(b.getRoot());
                                cout<<"\n";
                                break;
                        }
                        case 5:
                        {
                                cout<<"Enter the Seat no. to delete: ";
                                cin>>elt;
                                CNode * temp;
                                bool status;
                                temp = b.deleteElt(b.getRoot(),elt,status);
                                b.setRoot(temp);
                                if(status)
                                {
                                   cout<<"Deleted successfully\n";
                                }
                                else
                                {
                                   cout<<"Seat Not Found..!\n";
                                }
                                break;
                        }
                        case 6:
                        {
                                string title;
                                CNode* root = b.getRoot();
                                if(root == NULL)
                                {
                                   cout << "\nThe Tree is Empty so can't search\n" << endl;
                                   break;
                                }
                                cout << "Enter Seat no. to search: ";
                                cin >> elt;
                                CNode* found = b.search(root,elt);
                                if (found != NULL)
                                {
                                   cout << "Passenger found:" << endl;
                                   cout<<"Name.\t\tAge.\t\tDestination.\t\tSeatNo.\n";
                                   cout<<"================================================================\n";
                                   found->display();
                                }
                                else
                                {
                                   cout << "SeatNo not found!\n";
                                }
                                break;
                        }
                        case 7:
                        {
                                CNode* root = b.getRoot();
                                if(root == NULL)
                                {
                                   cout << "\nThe Tree is Empty so can't find Minimum\n" << endl;
                                   break;
                                }
                                CNode* min = b.findMin(root);
                                cout << "\n =====Minimum In the Tree=====\n" << endl;
                                cout<<"Name\t\tAge\t\tDestination\t\tSeatNo\n";
                                cout<<"================================================================\n";
                                min->display();
                                break;
                        }
                        case 8:
                        {
                                CNode* root = b.getRoot();
                                if(root == NULL)
                                {
                                   cout << "\nThe Tree is Empty..!\n" << endl;
                                   break;
                                }
                                CNode* max = b.findMax(root);
                                cout << "\n =====Maximum In the Tree=====\n" << endl;
                                cout<<"Name\t\tAge\t\tDestination\t\tseatNo\n";
                                cout<<"===============================================================\n";
                                max->display();
                                break;
                        }
                        case 9:
                        {
                           CNode*root = b.getRoot();
                           if(root != NULL)
                           {
                               cout << "Root" << endl;
                               cout<<"Name\t\tAge\t\tdestination\t\tseatNo\n";
                               cout<<"================================================================\n";
                               root->display();
                           }
                           else
                           {
                              cout << "Empty TREE" << endl;
                           }
                           break;
                        }
                        case 10:
                        {
                           int i=b.makeTreeEmpty();
                           if(i==0)
                              cout<<"Already tree is empty\n";
                           else
                              cout<<"Tree emptied Successfull\n";
                           break;
                        }
                        case 0:
                                cout << "Exiting..." << endl;
                                break;
                        default:
                                cout << "Invalid Choice" << endl;
                }
        }while(ch != 0);
}