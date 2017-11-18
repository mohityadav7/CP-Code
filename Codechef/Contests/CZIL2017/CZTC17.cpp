#include <bits/stdc++.h>
using namespace std;

bool isSame(int a[], int b[], int n){
    int flg=1;
    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            flg=0;
            return false;
        }
    }
    return true;
}

void change(int a[], int b[], int n){
    int c[n];

    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            c[i]=a[i];
        }
        a[b[i]-1]=c[i];
    }
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int a[n], b[n];
        for(int i=0; i<n; ++i)
            scanf("%d", &a[i]);
        for(int i=0; i<n; i++)
            scanf("%d", &b[i]);

        int count=0;
        do{
            cout<<"not same"<<endl;
            change(a,b,n);
            ++count;
        }while(!isSame(a,b,n));

        printf("%d\n", count);
    }

    return 0;
}
