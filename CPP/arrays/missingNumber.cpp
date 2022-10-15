#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    set<int>s;
    int flag=0;
    for(int i=1;i<n;++i)
    {
        int a;
        cin>>a;
        s.insert(a);
        if(a==n)
        {
            flag=1;
        }
    }
    int n1=0;
    if(flag)
    {
    for(auto x:s)
    {
    
        if(x-n1==2)
        {
        cout<<x-1;
        break;
        }
        n1=x;
    }
    }
    else
    cout<<n;
}
 
    