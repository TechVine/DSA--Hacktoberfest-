#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
int largest=l;
int l=2*i+1;
int r=2*i+2;
if(l<n&& arr[l]>arr[largest])
largest=l;
if(r<n&&arr[r]>arr[largest])
largest=r;
if(largest!=i){
swap(arr[i],arr[largest]);
heapify(arr ,n,largest);
}
}
void heapsort(int arr[],int n)
{
for(int i=n/2-1;i>=0;i--)
heapify(arr,n,i);
for(int i=n-1;i>0;i--){
swap(arr[0],arr[i]);
heapify(arr,i,0);
}
}
void printarray(int arr[],int n)
{
for(int i=0;i<n;++i)
cout<<arr[i]<< " ";
cout<<"\n";
}
int main()
{
int arr[]={12,11,13,5,6,7};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<"unsorted array:";
printArray(arr,n);
heapsort(arr,n);
cout<<"sorted array:";
printArray(arr,n);
system("read -p'\n' var");
return 0;
}
