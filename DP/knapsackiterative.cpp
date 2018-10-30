#include<bits/stdc++.h>
using namespace std;

int Kiterative(int *val,int *wt,int W,int n){
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int [W+1];
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int w=1;w<=W;w++){
			
			dp[i][w] = dp[i-1][w];
			if(wt[i-1] <= w ){
				dp[i][w] = max(dp[i-1][w],dp[i-1][w-wt[i-1]]+val[i-1]);
			}
		}
	}
	int ans = dp[n][W];
	return ans;
}

int main(){
	int val[]={5,4,1,3};
	int wt[] = {1,3,4,2};
	int W = 6;
	int output = Kiterative(val,wt,W,4);
	cout<<output<<endl;
	return 0;
}
