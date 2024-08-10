#include<bits/stdc++.h>
using namespace std;
int n,q;
typedef long long ll;
vector<pair<int,ll>> v[5001];
ll k;
int visited[5001];
int cnt=0;

void dfs(int node,ll value){
	//cout<<node<<" "<<value<<"\n";
	for(int i=0; i<v[node].size(); i++){
		if(!visited[v[node][i].first]){
			visited[v[node][i].first]=1;
			ll value2= min(value, v[node][i].second);
			if(value2>=k) cnt++;
			dfs(v[node][i].first,value2);
		}
	}
	return;
}


int main(){
	cin>>n>>q;
	
	for(int i=0; i<n-1; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		v[t1].push_back({t2,t3});
		v[t2].push_back({t1,t3});
	}
	
	for(int i=0; i<q; i++){
		int t1;
		cin>>k>>t1;
		cnt=0;
		memset(visited,0,sizeof(visited));
		visited[t1]=1;
		dfs(t1,1e16);
		cout<<cnt<<"\n";
	}
	
	return 0;
}
