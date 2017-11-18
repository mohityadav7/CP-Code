#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m,x,y;
    cin>>t;

    while(t--){
        cin>>n>>m;
        vector <vector <int> > v(n+1);
        int dist[n+1]={0};

        //making adjacency list for the graph
        for(int i=0; i<m; i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        queue <int> q;
        bool visited[n+1]={false};

        q.push(1);
        visited[1]=true;
        int distance=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0; i<v[node].size(); i++){
                if(!visited[v[node][i]]){
                    dist[v[node][i]]=dist[node]+1;
                    q.push(v[node][i]);
                    visited[v[node][i]]=true;
                }
            }
            ++distance;
        }
        cout<<dist[n]<<endl;
    }

    return 0;
}
