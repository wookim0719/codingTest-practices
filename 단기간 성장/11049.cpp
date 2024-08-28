#include<bits/stdc++.h>
using namespace std;
int n;
const int INF=987654321;
int dp[501][501];
vector<pair<int,int>> m;
int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		int t1,t2;
		cin>>t1>>t2;
		m.push_back({t1,t2});
	}
	
	for(int i=1; i<n; i++){
		for(int j=0; i+j<n; j++){
			dp[j][i+j]=INF;
		for(int k=j; k<=i+j; k++){
			dp[j][i+j] = min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+m[j].first*m[k].second*m[i+j].second);
		}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
