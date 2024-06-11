#include<bits/stdc++.h>
using namespace std;
int n,m,v;
vector<int> a[1004];
int visited[1004];
int visited2[1004];

void dfs(int s){
	cout<<s<<" ";
	if(a[s].size()){
		for(int i=0; i<a[s].size(); i++){
			if(!visited[a[s][i]]){
				visited[a[s][i]]=1;
				dfs(a[s][i]);
			}
		}
	}
	return;
}


int main(){
	cin>>n>>m>>v;
	queue<int> q;
	
	for(int i=0; i<m; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		a[temp1].push_back(temp2);
		a[temp2].push_back(temp1);
		}
		for(int i=0; i<=n; i++){
			if(a[i].size())
			sort(a[i].begin(),a[i].end());
		}
		visited[v]=1;
		visited2[v]=1;
		dfs(v);
		cout<<"\n";
		q.push(v);
		while(q.size()){
			cout<<q.front()<<" ";
			int temp=q.front();
			q.pop();
			for(int i=0; i<a[temp].size(); i++){
				if(!visited2[a[temp][i]]){
				visited2[a[temp][i]]=1;
				q.push(a[temp][i]);
				}
			}
		}
	
	return 0;
}
