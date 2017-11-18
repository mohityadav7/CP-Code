#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a, a+n);

        cout<<a[(n+k)/2]<<endl;
    }

    return 0;
}
