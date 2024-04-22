#include<bits/stdc++.h>
using namespace std;
int n,m,s,e;
int x,y,z;
int a[504][504], dist[504];
const int INF = 987654321;

void dijkstra() {
	fill(dist, dist+504, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	// 거리를 먼저 넣고 노드를 두번째에 넣는다.  
	pq.push(make_pair(0,s));
	dist[s] = 0;
	while(pq.size()){
		int here= pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist)continue;
		for(int i=0; i<n; i++){
			if(a[here][i] == -1) continue;
			int _dist = a[here][i];
			if(dist[i]> dist[here]+ _dist){
				dist[i] = dist[here] + _dist;
				pq.push(make_pair(dist[i],i));
			}
		} 
		
	}
}

void eraseEdge(){
	queue<int> q;
	q.push(e);
	//끝점을 기준으로 거리값이 i노드까지의 거리와 a[i][e]즉, 끝점까지의 거리 합이 같은 경우에
	// 그 점이 최단거리에 속하므로 그 값을 큐에 넣어주고 계속 찾는다. 
	while(q.size()){
		int cx= q.front(); q.pop();
		for(int i=0; i<n; i++){
			if(dist[cx] == dist[i]+ a[i][cx] && a[i][cx] != -1){
				a[i][cx] = -1;
				q.push(i);
			}
		}
	}
}

int main(){
	
	while(true){
		cin>>n>>m;
		if(n==0&&m==0)break;
		cin>>s>>e;
		memset(a,-1,sizeof(a));
		for(int i=0; i<m; i++){
			cin>>x>>y>>z;
			a[x][y]=z;
		}
		dijkstra();
        eraseEdge();
        dijkstra();
        printf("%d\n", dist[e] == INF ? -1 : dist[e]);
	}
	
	return 0;
}
