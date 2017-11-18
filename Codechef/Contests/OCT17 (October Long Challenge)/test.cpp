#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int main(){
    int isPresent[MAX]={0};
    int a[]={1, 0, 2};

    for(int i=0; i<MAX; ++i){
        isPresent[a[i]]=1;
    }
    //for(int i=0; i<MAX; i++)
        //cout<<isPresent[i]<<" ";

    return 0;
}
