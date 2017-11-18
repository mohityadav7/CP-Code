#include <iostream>
using namespace std;

int main(){
    int t, x,y, p,q;
    cin>>t;
    while(t--){
        cin>>x>>y>>p>>q;
        //up or down
        if(p==x){
            if(q-y > 0)
                cout<<"up"<<endl;
            else
                cout<<"down"<<endl;
        }
        //left or right
        else if(q==y){
            if(p-x > 0)
                cout<<"right"<<endl;
            else
                cout<<"left"<<endl;
        }
        //sad
        else{
            cout<<"sad"<<endl;
        }
    }

    return 0;
}
