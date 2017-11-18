#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,x,y;
    cin>>n;
    vector <pair <int, int> > v(n);
    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back(make_pair(y,x));
    }

    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" ";
    }


    return 0;
}
