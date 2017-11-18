#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,p, ncw, nh;
    cin>>t;
    while(t--){
        ncw = nh = 0;
        cin>>n>>p;

        int x;
        while(n--){
            cin>>x;
            if(x >= p/2){
                ++ncw;
            }
            else if(x <= p/10){
                ++nh;
            }
        }

        if(nh==2 && ncw==1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}
