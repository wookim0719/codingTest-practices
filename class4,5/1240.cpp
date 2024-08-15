#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> v[1001];
int visited[1001];

int main(){
	
	cin>>n>>m;
	for(int i=0; i<n-1; i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	
	for(int i=0; i<m; i++){
		memset(visited,0, sizeof(visited));
		queue<pair<int,int>> q;
		int a,b;
		cin>>a>>b; 
		q.push({a,0});
		visited[a]=1;
		while(q.size()){
			auto f= q.front();
		//	cout<<f.first<<" "<<f.second<<"\n";
			q.pop();
			if(f.first==b) {
				cout<<f.second<<"\n";
				break;
			}
			for(int i=0; i<v[f.first].size(); i++){
				if(!visited[v[f.first][i].first]){
					visited[v[f.first][i].first]=1;
					q.push({v[f.first][i].first,f.second+v[f.first][i].second});
				}
			}
		}
	}
	
	return 0;
}
