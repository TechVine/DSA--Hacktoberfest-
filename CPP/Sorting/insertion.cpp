#include<bits/stdc++.h>

using namespace std;

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j>0;j--)
        {
            if(arr[j]>=arr[j-1])
            {
                break;
            }
            swap(arr[j],arr[j-1]);
        }
    }
    for(i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
