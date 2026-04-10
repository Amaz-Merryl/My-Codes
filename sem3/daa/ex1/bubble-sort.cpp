#include<iostream>
using namespace std;
int main()
{
        int n,temp;
        bool flag;
        cout<<"No. of element : ";
        cin>>n;
        int A[n];
        cout<<"Enter the elements :\n";
        for(int i=0;i<n;i++)
                cin>>A[i];
        for(int i=0;i<=n-2;i++)
        {
                flag = false;
                for(int j=0;j<=n-2-i;j++)
                {
                        if(A[j]>A[j+1])
                        {
                                temp = A[j];
                                A[j] = A[j+1];
                                A[j+1] = temp;
                                flag = true;
                        }
                }
                if(!flag)
                        break;
        }
        cout<<"Sorted Arry : \n";
        for(int i=0;i<n;i++)
        {
                cout<<A[i]<<"\t";
        }
        return 0;
}
