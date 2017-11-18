#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q,l,r,d;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    cin>>q;
    while(q--){
        scanf("%d %d %d", &l,&r,&d);

        long long sum=0;
        for(int i=l, j=0; i<=r; i+=d, j++){
            cout<<"i="<<i<<" j="<<j<<endl;
            sum+=a[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}
