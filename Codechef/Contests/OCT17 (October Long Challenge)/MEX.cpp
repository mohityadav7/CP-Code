#include <bits/stdc++.h>
using namespace std;
#define MAX 200001

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

        sort(a, a+n); //sorting the elements of set
        bool isPresent[MAX]={false};

        for(int i=0; i<n; ++i)
            isPresent[a[i]]=true;

        //finding answer
        for(int i=0, c=0; i<MAX; ++i){
            if(isPresent[i]==false)
                ++c;
            if(c==k+1){
                cout<<i<<endl;
                break;
            }
        }
    }

    return 0;
}
