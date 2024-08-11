#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> T;
int n,m;
vector<T> v;
int parents[100001];
int mv;
int ans;

int check(int node){
	if(parents[node]==node){
		return node;
	}
	else{
	return parents[node]= check(parents[node]);
	}
}

void sssss(int node, int node2){
	node=check(node);
	node2=check(node2);
	parents[node2]=node;
	return;
}


int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({c,{a,b}});
	}
	sort(v.begin(),v.end());
	
	for(int i=1; i<=n; i++){
		parents[i]=i;
	}
	int cnt=0;
	for(int i=0; i<v.size(); i++){
		T curEdge= v[i];
		int cost= v[i].first;
		int now= v[i].second.first;
		int next= v[i].second.second;
		
		if(check(now)==check(next)) continue;
		sssss(now,next);
		mv= max(mv,cost);
		ans+=cost;
		cnt++;
		if(cnt == n-1)break;
	}	
	
	
	cout<<ans-mv;
	
	
	return 0;
}
