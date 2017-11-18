#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,a,b,x,y;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int i=0;
        int ans[10]={0};
        while(a || b){
            x=a%10;
            y=b%10;
            a/=10;
            b/=10;
            ans[i++]=(x+y)%10;
        }
        if(i==0){
            cout<<"0";
        }
        while(i){
            cout<<ans[--i];
        }
        cout<<endl;

    }
    return 0;
}
