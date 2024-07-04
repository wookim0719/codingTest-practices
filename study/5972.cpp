#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v[50001];
//int visited[50001];
int dist[50001];
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

//void go(int now,int temp){
//	for(auto i:v[now]){
//		if(i.first==n){
//			temp+=i.second;
//				//cout<<now<<"\n";
//			ret= min(ret,temp);
//			return;
//			}
//		}
//	for(auto i:v[now]){
//		if(!visited[i.first]){
//			visited[i.first]=1;
//			go(i.first,temp+i.second);
//			visited[i.first]=0;
//		}
//	}
//	return;
//}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		v[temp1].push_back({temp2,temp3});
		v[temp2].push_back({temp1,temp3});
	}
	fill(dist,dist+50001,987654321);
	
	pq.push({0,1});
	while(pq.size()){
		int here=pq.top().second;
		int here_dist= pq.top().first;
		pq.pop();
		
		for(pair<int,int> there: v[here]){
			int _dist= there.second;
			int _there = there.first;
			if(dist[_there]>_dist+here_dist){
				dist[_there] = _dist+ here_dist;
				pq.push({dist[_there],_there});
			}
		}
	}
	
	cout<<dist[n];
	return 0;
}
