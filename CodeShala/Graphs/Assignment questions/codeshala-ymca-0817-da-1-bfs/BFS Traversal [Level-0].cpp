#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector <int> >v(n+1);
        for(int i=0; i<m; i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        /*
        //printing the adjacency list
        for(int i=1; i<=n; i++){
            for(int j=0; j<v[i].size(); j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        */

        queue<int>q;
        bool visited[n+1]={false};

        q.push(1);
        visited[1]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(int i=0; i<v[node].size(); i++){
                if(!visited[v[node][i]]){
                    q.push(v[node][i]);
                    visited[v[node][i]]=true;
                }
            }
        }
    }

    return 0;
}
