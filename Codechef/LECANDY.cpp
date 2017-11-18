#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int a[n], count = 0;;
        for(int i=0; i<n; i++){
            cin>>a[i];
            count+=a[i];
        }
        if(count <= c)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
