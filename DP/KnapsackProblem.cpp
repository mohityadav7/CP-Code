#include<bits/stdc++.h>
using namespace std;
struct all{
	int ans;
	int weight;
};
all Kpsack(int n,int W,int* val,int * wt){
//	all ** dp= new all*[n+1];
//	for(int i=0;i<=n;i++){
//		dp[i] = new all [W];
//		for(int j=0;j<W;j++){
//			dp[i][j] = -1
//		}
//	}
	all ob1;
	if(W<=0){
		ob1.ans=0;
		ob1.weight = W
		return ob1;
	}
	if(n==0){
		ob1.ans = 0;
		ob1.weight =W;
		return ob1;
	}
	if(wt[n-1]<=W){
		int  option1= val[n-1]+Kpsack(n-1,W-wt[n-1],val,wt);
		int  option2= Kpsack(n-1,W,val,wt);
		ob1.ans = max(option1,option2);
		ob1.weight = W;
		return ob1;
	}else{
		ob1.ans = Kpsack(n-1,W,val,wt);
		ob1.weight = W;
		return  ob1;
	}
}

int main(){
	int n;
	cin>>n;
	int* val = new int [n];
	int* wt = new int [n];
	//cin>>n;
	cout<<"Value"<<endl;
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	cout<<"Weights of The Respective Values"<<endl;
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	int W;
	//cin>>W;
	cout<<"Max. Possible Weight in a knapsack"<<endl;
	cin>>W;
	all output = Kpsack(n,W,val,wt);
	cout<<output.ans<<output.weight<<endl;
	return 0;
}
