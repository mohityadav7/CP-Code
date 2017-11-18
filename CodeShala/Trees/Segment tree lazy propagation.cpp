#include <bits/stdc++.h>
using namespace std;

int tree[10000], lazy[100000]={0};
int arr[10000];

// function to update the segment tree by updating the value at a specific range
void update_tree(int node, int st, int en, int ust, int uen, int val){
    if(lazy[node]){
        tree[node]+=(lazy[node]*(en-st+1));
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node + 1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if((ust>st && ust>en) || (uen<st && uen<en))
        return;
    /*
    if(st==en && index==st){
        tree[node]=val;
        return;
    }*/
    //if update range lie inside node range
    if(ust<=st && uen>=en){
        tree[node]+=val*(en-st+1);
        if(st!=en){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }

    int mid=(st+en)/2;
    update_tree(2*node, st, mid, ust, uen, val);
    update_tree(2*node+1, mid+1, en, ust, uen, val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

// function to calculate the sum from index st to index en
int query_tree(int node,int qst,int qen,int st,int en){
    if(qen<st || qst>en)
        return 0;

    if(lazy[node]){
        tree[node]+=(lazy[node]*(en-st+1));
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node + 1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(qst<=st && qen>=en)
        return tree[node];

    int mid=(st+en)/2;
    int l_arr=query_tree(2*node,qst,qen,st,mid);
    int r_arr=query_tree(2*node+1,qst,qen,mid+1,en);
    return l_arr+r_arr;
}

// build segment tree
int build_tree(int node, int st, int en){
    //terminating condition
    if(st==en){
        tree[node]=arr[st];
        return tree[node];
    }
    int mid=(st+en)/2;
    int l_sum=build_tree(2*node,st,mid);
    int r_sum=build_tree(2*node+1,mid+1,en);
    tree[node] = l_sum + r_sum;
    return tree[node];
}

int main(){
    int n,i,value,index, q,l,r,qst,qen,ust,uen;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>arr[i];
    build_tree(1,1,n);

    for(i=1;i<2*n;i++)
       cout<<tree[i]<<" ";
    cout<<endl;

    cin>>ust>>uen>>value;

    update_tree(1,1,n,ust,uen,value);

    for(i=1;i<2*n;i++)
        cout<<tree[i]<<" ";
    cout<<endl;

    cin>>qst>>qen;
    cout<<query_tree(1,qst,qen,1,n);

    /*
    cin>>q;
    while(q--){
        cin>>qst>>qen;
        cout<<query_tree(1,1,n,qst,qen);
    }*/

    return 0;
}
