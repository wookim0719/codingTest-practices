#include<bits/stdc++.h>
using namespace std;
int n,m;
int ret;
int visited[100001];

int main(){

cin>>n>>m;
queue<pair<int,int>> q;
q.push({n,0});
visited[n]=1;

while(q.size()){
	auto current= q.front();
	q.pop();
	if(current.first==m){
		ret= current.second;
		break;
	}
	
	if(current.first+1<=100000&&!visited[current.first+1]){
		visited[current.first+1]=1;
		q.push({current.first+1,current.second+1});
	}
	if(current.first*2<=100000&&!visited[current.first*2]){
		visited[current.first*2]=1;
		q.push({current.first*2,current.second+1});
	}
	if(current.first-1>=0&&!visited[current.first-1]){
		visited[current.first-1]=1;
		q.push({current.first-1,current.second+1});
	}
}
	
	cout<<ret;
	
	return 0;
}
