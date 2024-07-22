#include<bits/stdc++.h>
using namespace std;
int v,e;
int dp[20001];
vector<pair<int,int>> edges[20001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
	fill(dp,dp+20001,987654321);
	cin>>v>>e;
	int start;
	cin>>start;
	dp[start]=0;
	for(int i=0; i<e; i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges[a].push_back({b,c});
	}
	
	pq.push({0,start});
	
	while(pq.size()){
		auto cur= pq.top();
		pq.pop();
		for(auto next: edges[cur.second]){
			if(dp[next.first]>dp[cur.second]+next.second){
				dp[next.first]= dp[cur.second]+next.second;
				pq.push({dp[next.first],next.first});
			}
		}
	}
	
	for(int i=1; i<=v;i++){
		if(dp[i]==987654321) cout<<"INF"<<"\n";
		else cout<<dp[i]<<"\n";
	}
	
	return 0;
}
