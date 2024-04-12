#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q,w,e;
ll dist[501];
const ll INF = 987654321;

int main(){
	cin>>n>>m;
	vector<pair<int,int>> adj[6004];
	for(int i=0; i<m; i++){
		cin>>q>>w>>e;
		adj[q-1].push_back({w-1,e});
	}
	
	fill(dist, dist +n+1, INF);
	dist[0]=0;
	queue<int> q;
	
	for(int i=0; i<=n; i++){
		for(int here = 0; here<n; here++){
			for(auto there: adj[here]){
				int d = there.second;
				int to  = there.first;
			if(dist[here] != INF && ((dist[here] + d) <dist[to])){
				if(i==n-1) q.push(to);
				dist[to] = dist[here]+d;
			}
			}
		}
	}
	if(q.size()) cout<<-1;
	else for(int i=1; i<n; i++) cout<<(dist[i] == INF? -1: dist[i])<<"\n";
	
	return 0;
}
