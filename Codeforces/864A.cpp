#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], h[101]={0};
    for(int i=0; i<n; i++){
        cin>>a[i];
        h[a[i]]++;
    }

    int nonZeroCount=0,x=0,y=0;
    for(int i=0; i<101; i++){
        if(h[i]>0){
            nonZeroCount++;
            if(x==0)
                x=i;
            else if(y==0)
                y=i;
        }
    }

    if(nonZeroCount==2 && h[x]==h[y])
        cout<<"YES"<<endl<<x<<" "<<y<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
