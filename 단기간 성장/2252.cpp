#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> back;
vector<vector<int>> front;
vector<bool> visited;
vector<int> ret;


void dfs(int now){
	if(front[now].size()){
		for(int i=0; i<front[now].size(); i++){
			if(!visited[front[now][i]]){
				visited[front[now][i]]=1;
				dfs(front[now][i]);	
			}
		}
}
	ret.push_back(now);

	return;
}


int main(){
	cin>>n>>m;
	visited.resize(n + 1, false);
	front.resize(n + 1);
	back.resize(n+1)
	for(int i=0; i<m; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		back[temp1].push_back(temp2);
		front[temp2].push_back(temp1);
	}
	
	for(int i=1; i<=n; i++){
		if(back[i].size()==0){
			dfs(i);
		}
	}
	
	for(int i=0; i<ret.size(); i++)
	cout<<ret[i]<<" ";	
	
	return 0;
}
