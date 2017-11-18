#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        int divCount=0;
        cin>>n;
        for(int i=1, sn=sqrt(n); i<=sn; i++){
            if(i*i == n){
                divCount++;
                cout<<endl;
            }
            else if(n%i == 0){
                divCount+=2;
                cout<<i<<endl<<n/i<<endl;
            }
        }
        cout<<divCount<<endl<<endl;
    }

	return 0;
}
