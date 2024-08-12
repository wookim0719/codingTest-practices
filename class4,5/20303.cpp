#include<bits/stdc++.h>
using namespace std;
vector<int> v[30001];
int candy[30001];
int visited[30001];
vector<pair<int,int>> r;
int k,m,n;
int ret[30001];

void bfs(int node){
	queue<int> q;
	int sum=0;
	int cnt=0;
	q.push(node);
	while(q.size()){
		int f= q.front();
		cnt++;
		q.pop();
		sum+=candy[f];
		for(int i=0; i<v[f].size(); i++){
			int next= v[f][i];
			if(!visited[next]){
				q.push(next);
				visited[next]=1;
			}
		}
	}
	if(cnt<k){
		r.push_back({cnt,sum});
	}
	
	return ;
}

int main(){
	cin>>n>>m>>k;	
	
	for(int i=1; i<=n; i++){
		cin>>candy[i];
	}
	
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	for(int i=1; i<=n; i++){
	if(!visited[i]){
	visited[i]=1;
	bfs(i);	
	}	
	}
	
	for(int i=0; i<r.size(); i++){
		for(int j=k-1; j>=r[i].first; j--){
			ret[j] = max(ret[j],r[i].second+ret[j-r[i].first]);
		}
	}
	cout<<ret[k-1];
	return 0;
}
