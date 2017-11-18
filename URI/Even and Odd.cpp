#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++){
        if(a[i]%2==0)
            cout<<a[i]<<endl;
    }
    for(int i=n-1; i>=0; i--){
        if(a[i]%2!=0)
            cout<<a[i]<<endl;
    }

    return 0;
}
