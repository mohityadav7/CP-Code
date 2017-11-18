#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;

        int zeroCount=0;
        for(int i=5; i<=n; i*=5){
            zeroCount += floor(n/i);
        }
        cout<<zeroCount<<endl;
    }

    return 0;
}
