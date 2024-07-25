#include<bits/stdc++.h>
using namespace std;
int n,m;
int s,d;
vector<pair<int,int>> v[1001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<m; i++){
	int temp1,temp2,temp3;
	cin>>temp1>>temp2>>temp3;
		v[temp1].push_back({temp3,temp2});
	}	
	cin>>s>>d;	
	fill(dist,dist+1001,987654321);
	dist[s]=0;
	pq.push({0,s});

	while(pq.size()){
		auto current= pq.top();
		pq.pop();
		for(auto next: v[current.second]){
			if(current.first>dist[d]) break;
			if(dist[next.second]>current.first+next.first){
				dist[next.second]=current.first+next.first;
				pq.push({dist[next.second],next.second});
			}
		}
	}
	
	cout<<dist[d];

	return 0;
}
