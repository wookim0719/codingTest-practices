#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int dp[2000001];
int ret;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1; i<=n; i++){
		int t1,t2;
		cin>>t1>>t2;
		if(dp[i]<dp[i-1]) dp[i]=dp[i-1];
		dp[i+t1-1] = max(dp[i+t1-1],dp[i-1]+t2);
	}
//	for(int i=1; i<=n; i++){
//		cout<<dp[i]<<" ";
//	}
	cout<<dp[n];
	
	return 0;
}
