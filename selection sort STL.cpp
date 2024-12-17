/// Write a function template for selection sort that inputs, sorts and outputs an integer array and 
// a float array.

#include<iostream>
using namespace std;

#define size 10
template<typename t>
void sel(t a[size])
{
    int n;
    int i,j,min;
    t temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    cout<<"Sorted arry";
    for(i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }
}

int main()
{
    int a[size];
    float b[size];
    int n;
    int i;
    int ch;
    while(true)
    {
        cout<<"\nMenu\n";
        cout<<"\n1.integar value\n2.float value";
        cout<<"\nEnter choice number: ";
        cin>>ch;
        
        
        switch(ch){
            case 1:
            cout<<"Enter total numebr of integers: ";
            cin>>n;
            cout<<"Enter the int elements:";
            for(i=0;i<n;i++){
                cin>>a[i];
            }
            sel(a);
            break;
            
            case 2:
            cout<<"Enter the total number of float: ";
            cin>>n;
            cout<<"ENter the float elements: ";
            for(i=0;i<n;i++){
                cin>>b[i];
            }
            sel(b);
            break;
            
            case 3:
            exit(0);
            break;
        }
        
    }while(ch != 3);
    return 0;
}
