#include<bits/stdc++.h>
using namespace std;
const int INF =987654321;
int n,m;
vector<pair<int,int>> v;
vector<int> cap;
vector<int> cost;
int dp[10000001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		cap.push_back(temp);
	}
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		cost.push_back(temp);
	}
	
	for(int i=0; i<n; i++){
		v.push_back({cost[i],cap[i]});
	}
//	sort(v.begin(),v.end());
	
	fill(dp,dp+10000001,INF);
	
	dp[0]=0;
	for(int i=0; i<n; i++){
		//드는 비용  
		int c= v[i].first;
		//줄어드는 메모리  
		int s= v[i].second;
		for(int j=m; j>0; j--){
			if(j>=s){
				dp[j] = min(dp[j],dp[j-s]+c);
			}
			else{
				dp[j] = min(dp[j],c);
			}
		}
	}
	
	cout<<dp[m];
	
	return 0;
}
