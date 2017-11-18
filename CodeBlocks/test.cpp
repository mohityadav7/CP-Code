#include <iostream>
using namespace std;

long long pwr(long long int a, long long int b){
    if(b==0)
        return 1;
    else if(b%2==0){
        return (pwr(a,b/2)*pwr(a,b/2));
    }
    else{
        return (a*pwr(a,b-1));
    }
}

int main()
{
    int p,q,r,t;
    cin>>t;
    while(t--){
        cin>>p>>q>>r;
        int pq=pwr(p,q);
        int x=pq/r;
        int m=x*r, n=r*(x+1);
        cout<<"m="<<m<<" n="<<n<<endl;
        if(m%pq < n%pq)
            cout<<m<<endl;
        else
            cout<<n<<endl;
    }

    return 0;
}
