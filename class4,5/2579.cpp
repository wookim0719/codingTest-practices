#include<bits/stdc++.h>
using namespace std;
int n;
int dp[301][2];
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	dp[1][0] = v[0];
	dp[1][1]=0;
	
	for(int i=2; i<=n; i++){
		if(i>=2){
			dp[i][0]= max(dp[i][0],dp[i-2][0]+v[i-1]);
			dp[i][0]= max(dp[i][0],dp[i-2][1]+v[i-1]);
		}
		dp[i][1]= max(dp[i][1],dp[i-1][0]+v[i-1]);
	}
		
	cout<<max(dp[n][1],dp[n][0]);
	
	return 0;
}
