#include<bits/stdc++.h>
using namespace std;
int lcsI(char *s1 ,char *s2){
	int m = strlen(s1);
	int n = strlen(s2);
	
	int ** dp = new int * [m+1];
	for(int i=0;i<=m;i++){
		dp[i] = new int [n+1];
	}
	for(int i=0;i<=m;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[0][i] = 0;
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[m-i] == s2[n-j]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans = dp[m][n];
	for(int i=0;i<=m;i++){
		delete [] dp [i];
	}
	return ans;
	
	
}
int main(){
	char s1 [100];
	char s2	[100];
	cin>>s1;
	cin>>s2;
	cout<<lcsI(s1,s2)<<endl;
	return 0;
}
