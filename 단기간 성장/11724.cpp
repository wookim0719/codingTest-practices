#include<bits/stdc++.h>
using namespace std;
int n,m;
int visited[1001];
int cnt;
vector<int> v[1001];


void dfs(int now){
	for(int i=0; i<v[now].size(); i++){
		if(!visited[v[now][i]]){
			visited[v[now][i]]=1;
			dfs(v[now][i]);
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	
	for(int i=1 ;i<=n; i++){
		if(!visited[i]){
			visited[i]=1;
			dfs(i);
			cnt++;
		}
	}	
	
	cout<<cnt;
	return 0;
}
