#include<iostream>
using namespace std;
void swapping (int&a,int&b){
int temp;
temp=a;
a=b;
b=temp;
}
void display (int*array,int size)
for(int i=0;i<size;i++)
cout<<array[i]<< " ";
cout<<endl;
}
void merge(int*array,int l,int m,int r){
int i,j,k,nl,nr;
nl=m-l+1;
nr=r-m;
int l arr[nl],r arr[nr];
for(i=0;i<nl;i++)
l arr[i]=array [l+i];
for(j=0;j<nr;j++)
r arr[j]=array[m+1+j];
i=0;j=0;k=l;
while(i<nl&&j<nr){
if(l arr[i]<=r arr[j]){
array[k]=l arr[i];
i++;
}else{
array[k]=r arr[j];
j++;
}
k++;
}
while(i<nl){
array[k]=l arr[i];
i++;k++;
}
while(j<nr){
array[k]=r arr[j];
j++;k++;
}
}
void mergesort(int*array,int l,int r){
int m;
if(l<r){
int m=l+(r-1)/2;
mergesort(array,l,m);
mergesort(array,m+1,r);
merge(array,l,m,r);
}
}
int main()
{
int n;
cout<<"enter the number of elements:";
cin>>n;
int arr[n];
cout<<"enter elements:";<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"array before sorting:";
display(arr,n);
mergesort(arr,0,n-1);
cout<<"array after sorting:";
display (arr,n);
}
