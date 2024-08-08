#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[100001];
int n;
int visited[100001];

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp1;
		cin>>temp1;
		while(true){
 			int temp2,temp3;
 			cin>>temp2;
 			if(temp2==-1) break;
 			cin>>temp3;
 			v[temp1].push_back({temp2,temp3});
		}
	}
	int fn=1;
	visited[fn]=1;
	queue<pair<int,int>> q1;
	q1.push({fn,0});
	int ret1=0;
	while(q1.size()){
		auto cur= q1.front();
		q1.pop();
		for(auto next: v[cur.first]){
			if(!visited[next.first]){
				visited[next.first]=1;
				ret1= max(ret1,cur.second+next.second);
				if(ret1==cur.second+next.second) fn=next.first;
				q1.push({next.first,cur.second+next.second});
			}
		}
	}
	memset(visited,0,sizeof(visited));
	visited[fn]=1;
	q1.push({fn,0});
	int ret2=0;
	while(q1.size()){
		auto cur= q1.front();
		q1.pop();
		for(auto next: v[cur.first]){
			if(!visited[next.first]){
				visited[next.first]=1;
				ret2= max(ret2,cur.second+next.second);
				q1.push({next.first,cur.second+next.second});
			}
		}
	}
		
	cout<<ret2;
	return 0;
}
