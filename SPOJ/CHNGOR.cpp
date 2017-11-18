#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,ans;
    cin>>t;
    while(t--){
        scanf("%d", &n);
        int a[n];
        ans=0;
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            ans = ans | a[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}
