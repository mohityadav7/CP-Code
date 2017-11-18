#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n,majority=0,i,count=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];

     majority=a[0];
    for(i=0;i<n;i++)
    {
        cout<<"hello";
        if(count==0)
            majority=a[i];
        if(a[i]==majority)
            count+=1;
        else
            count-=1;
    }
    cout<<majority<<endl;
}
