#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[100001];
int parent[100001];
int visited[100001];

void go(int node){
	
	for(int i=0; i<v[node].size(); i++){
		if(!visited[v[node][i]]){
			visited[v[node][i]]=1;
			parent[v[node][i]]= node;
			go(v[node][i]);	
		}
	}
	
	return ;
}



int main(){
	cin>>n;
	
	for(int i=0; i<n-1; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	
	visited[1]=1;
	go(1);
	
	for(int i=2; i<=n; i++){
		cout<<parent[i]<<"\n";
	}
	
	return 0;
}
