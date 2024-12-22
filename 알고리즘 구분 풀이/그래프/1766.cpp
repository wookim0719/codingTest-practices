#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> child[32001];
int degree[32001];
int visited[32001];
priority_queue<int,vector<int>,greater<int>> pq;

void go(int num){
	visited[num]=1;
	cout<<num<<" ";
	for(int i:child[num]){
		degree[i]--;
		if(degree[i]==0){
			pq.push(i);
		}
	}
	return ;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		child[t1].push_back(t2);
		degree[t2]++;
	}
	
	for(int i=1; i<=n; i++){
		sort(child[n].begin(),child[n].end());	
	}
	int cnt=0;
	
	for(int i=1; i<=n; i++){
		if(!degree[i]){
			pq.push(i);
		}
	}
	
	while(pq.size()){
		int f= pq.top();
		pq.pop();
		go(f);	
	}

	
	return 0;
}
