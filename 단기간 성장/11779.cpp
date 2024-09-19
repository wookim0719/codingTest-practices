#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<pair<int,int>> v[1001];
pair<int,int> dp[1001];
int s,e;
const int INF =987654321;

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t1--; t2--;
		v[t1].push_back({t2,t3});
	}
	cin>>s>>e;
	s--; e--;
	for(int i=0; i<n; i++) dp[i]={INF,0};
	dp[s]={0,0};
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,s});
	while(pq.size()){
		auto f= pq.top();
		int now= f.second;
		int a = f.first;
		pq.pop();
		if(dp[now].first<a) continue;
		for(auto next: v[now]){
			if(dp[next.first].first>a+next.second){
				dp[next.first].first= a+next.second;
				dp[next.first].second = now;
				pq.push({dp[next.first].first,next.first});
			}
		}	
	}
	
//	for(int i=0; i<n;i ++){
//		
//	}
	int node= e;
	vector<int> res;
	res.push_back(node+1);
	while(true){
		node = dp[node].second;
		res.push_back(node+1);
		if(node==s){
			break;
		}
	}
	cout<<dp[e].first<<"\n";
	cout<<res.size()<<"\n";
	
	for(int i=res.size()-1; i>=0; i--){
		cout<<res[i]<<" ";
	}	
	
	return 0;
}
