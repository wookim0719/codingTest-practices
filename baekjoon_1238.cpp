#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[1001][1001];
int dist[1001];
int return_dist[1001];
int res;
const int INF = 987654321;

int dijikstra(int s){
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	fill(dist,dist+1001, INF);
	dist[s] = 0;
	pq.push({0,s});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(int i=1; i<=n; i++){
			if(a[here][i] == -1) continue;
			int next = i;
			int d = a[here][i];
			if(dist[i] > dist[here]+d){
			//	cout<<here<<" "<<i<<" "<<dist[i]<<" "<< dist[here]+d<<"\n";
				dist[i] = dist[here]+d;
				pq.push(make_pair(dist[i], next));
			}
		}
	}
	//for(int i=1; i<=n; i++) cout<<dist[i]<<"\n";
	return dist[x];
}

void dijikstra2(){
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	fill(dist,dist+1001, INF);
	dist[x] = 0;
	pq.push({0,x});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(int i=1; i<=n; i++){
			if(a[here][i] == -1) continue;
			int next = i;
			int d = a[here][i];
			if(dist[i] > dist[here]+d){
			//	cout<<here<<" "<<i<<" "<<dist[i]<<" "<< dist[here]+d<<"\n";
				dist[i] = dist[here]+d;
				pq.push(make_pair(dist[i], next));
			}
		}
	}
	for(int i=1; i<=n; i++){
		return_dist[i] = dist[i];
	}
}





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	cin>>n>>m>>x;
	memset(a,-1,sizeof(a));
	for(int i=0; i<m; i++){
		int temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		a[temp1][temp2] = temp3;
	}
	dijikstra2();
	for(int i=1; i<=n; i++){
		int temp4= dijikstra(i);
		//cout<<i<<" "<<temp4+return_dist[i]<<"\n";
		res = max(res,temp4+return_dist[i]);
	}
	
	cout<<res;
	return 0;	
}
