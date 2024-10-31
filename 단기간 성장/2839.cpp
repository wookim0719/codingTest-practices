#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[5001];
int n;
int main(){
	cin>>n;
	fill(dp,dp+5001,INF);
	dp[0]=0;
	for(int i=1; i<=n; i++){
		if(i>=3){
			dp[i] = min(dp[i],dp[i-3]+1);
		}
		if(i>=5){
			dp[i] = min(dp[i],dp[i-5]+1);
		}
	}
	
	if(dp[n]==INF) cout<<-1;
	else
	cout<<dp[n];
	return 0;
}
