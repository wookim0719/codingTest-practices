#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[101];
int visited[101];
int cnt;

int main(){
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	
	queue<int> q;
	visited[1]=1;
	q.push(1);
	
	while(q.size()){
		int now=q.front();
		q.pop();
		for(int next:v[now]){
			if(!visited[next]){
				visited[next]=1;
				q.push(next);
				cnt++;
			}	
		}
	}
	
	cout<<cnt;
	
	return 0;
}
