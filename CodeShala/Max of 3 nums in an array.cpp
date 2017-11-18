#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a, a+n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    if(a[n-1]<0){
        cout<<a[0]*a[1]*a[2]<<endl;
    }
    else if(a[n-1]<0 && a[n-2]>0){

    }
    else if(a[n-1]<0 && a[n-2]<0 && a[n-3]>0){

    }
    else{
        cout<<a[n-1]*a[n-2]*a[n-3]<<endl;
    }


    return 0;
}
