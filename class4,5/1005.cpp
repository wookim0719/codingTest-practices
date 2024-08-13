#include<bits/stdc++.h>
using namespace std;
int t;
int c[1001];
vector<int> v[1001];
int dp[1001];


int dfs(int node){
	if(v[node].size()==0) return c[node-1];
	int &ret= dp[node];
	if(ret!=-1) return ret;
	for(int i=0; i<v[node].size(); i++){
		ret = max(ret,c[node-1]+dfs(v[node][i]));
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>t;
	
	while(t--){
		fill(dp,dp+1001,-1);
		for(int i=0; i<1001; i++){
			v[i].clear();
		}
		int n,m;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			cin>>c[i];
		}
		for(int i=0; i<m; i++){
			int a,b;
			cin>>a>>b;
			v[b].push_back(a);
		}
		int target;
		cin>>target;
		int res = dfs(target);
		cout<<res<<"\n";	
		}	
	return 0;
}
