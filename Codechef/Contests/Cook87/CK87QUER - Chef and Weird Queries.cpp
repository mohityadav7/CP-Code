#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,b;
    long long a,y,count;
    cin>>t;
    while(t--){
        count=0;
        cin>>y;
        for(int a=1; a*a<y; a++){
            count += (y-a*a <= 700)?(y-a*a):(700);
        }
        cout<<count<<endl;
    }

    return 0;
}
