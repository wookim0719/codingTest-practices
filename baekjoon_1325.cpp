#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[10001];
int visited[10001], dp[10001];
int ret;
int max_value;
vector<int> com; 

int dfs(int num){
	visited[num] =1;
	int cnt=1;
	for(int i=0; i< adj[num].size(); i++){
		if(visited[adj[num][i]]) continue;
		cnt += dfs(adj[num][i]);
	}

	return cnt;
}

int main(){

cin>> n>> m;

for(int i=0; i<m; i++){
	int child;
	int parent;
	cin>> child>> parent;
	adj[parent].push_back(child);
}	

for(int i=1; i<n+1; i++){
	memset(visited, 0, sizeof(visited));
	dp[i] = dfs(i);
	max_value = max(dp[i], max_value);
}

	for (int i = 1; i <= n; i++) if (max_value == dp[i]) cout << i << " "; 


return 0;
}
