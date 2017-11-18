#include <bits/stdc++.h>
using namespace std;

int n,m; //no. of rows and columns
int a[40][40]; //input matrix
int LISLenCount=0, tempCount; //length of longest consecutive increasing sequence
int current; //current letter in sequence

void dfs(int x, int y){
    //utility arrays to make the traversing easy
    int posX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int posY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i=0; i<8; i++){
        int p = x+posX[i], q = y+posY[i];

        if(p>=0 && p<n && q>=0 && q<m){

            //debug
            //cout<<"p="<<p<<" q="<<q<<"  a["<<p<<"]["<<q<<"]="<<a[p][q]<< "  i="<<i<<endl;

            if(a[p][q] == current+1){
                //cout<<(char)(a[p][q]+65)<<endl;
                ++current;
                ++tempCount;
                //cout<<"DFS: calling dfs for "<<"a["<<p<<"]["<<q<<"]"<<endl;
                dfs(p,q);
                break;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        getchar();
        for(int j=0; j<m; j++){
            a[i][j] = getchar()-65;
        }
    }

    //counting length of longest consecutive increasing sequence starting from 'A'
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                tempCount=1, current=0;
                dfs(i,j);
                if(tempCount > LISLenCount)
                    LISLenCount = tempCount;
            }
        }
    }
    cout<<LISLenCount;

    return 0;
}
