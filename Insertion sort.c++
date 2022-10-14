#include<iostream>
using namespace std;
void insertion sort(int arr[],int n)
int i,key,j;
for(i=1;i<n;i++)
{
key=arr[i];
j=i-1;
while(j>=0&&arr[j]>key)
{
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
}
void printarray(int arr[],int n)
{
int i;
for(i=0;i<n;i++)
cout<<arr[i]<< " ";
cout<<endl;
}
int main()
{
int arr[]={12,11,13,5,6};
int n=size of (arr)/size of (arr[0]);
cout<<"unsorted array:";
printarray(arr,n);
insertionsort(arr,n);
cout<<"sorted array:";
printarray(arr,n);
system("read -p'\n' var");
return 0;
}
