#include<bits/stdc++.h>
using namespace std;
int t;
int dp[41];
int dp2[41];

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	dp[0]=1;
	dp2[0]=0;
	dp[1]=0;
	dp2[1]=1;
	dp[2]=1;
	dp2[2]=1;
	for(int i=3; i<=40; i++){
		dp[i]= dp[i-1]+dp[i-2];
		dp2[i]= dp2[i-1]+dp2[i-2];
	}
	while(t--){
		int temp;
		cin>>temp;
		cout<<dp[temp]<<" "<<dp2[temp]<<"\n";
	}
	return 0;
}
