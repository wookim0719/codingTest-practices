#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v[1001];
int ret;
int visited[1001];
int startP;
int endP;
bool flag=false;
struct nd{
	int pre;
	int now;
	int sum;
};

void go(int idx){
	fill(visited,visited+1001,0);
	visited[idx]=1;
	queue<nd> q;
	nd temp2;
	temp2.now =idx;
	temp2.sum = 0;
	temp2.pre = -1;
	q.push(temp2);
	while(q.size()){
		auto value = q.front();
		int now= value.now;
		int sum = value.sum;
		int pre = value.pre;
		q.pop();
		if(ret<sum&&idx<now){
			startP = idx;
			endP = now;
			ret=sum;
		}
		for(int i=0; i<v[now].size(); i++){
			if(!visited[v[now][i].second]){
				visited[v[now][i].second]=1;
				nd temp;
				temp.now = v[now][i].second;
				temp.sum = v[now][i].first+sum;
				temp.pre = now;
				q.push(temp);
			}
			if(visited[v[now][i].second]&&v[now][i]!=pre) flag=true;
		}
	}
	return;
}

int main() {
	cin>>n;
	for(int i=0; i<n-1; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		v[t1-1].push_back({t3,t2-1});
		v[t2-1].push_back({t3,t1-1});
	}
	for(int i=0; i<n; i++)
	go(i);
	if(flag) cout<<-1;
	cout<<ret<<"\n";
	cout<<startP+1<<"\n";
	cout<<endP+1;
	return 0;
}
