#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int dy[8]={-1,-1,1,1,2,2,-2,-2};
	int visited[301][301];
	int dx[8]={2,-2,2,-2,-1,1,-1,1};
	
	while(t--){
		memset(visited,0,sizeof(visited));
		int l;
		cin>>l;
		int y,x,desy,desx;
		cin>>y>>x>>desy>>desx;
		visited[y][x]=1;
		queue<pair<pair<int,int>,int>> q;
		q.push({{y,x},0});
		while(q.size()){
			auto f= q.front();
			int yy=f.first.first;
			int xx=f.first.second;
			q.pop();
			if(yy==desy&&xx==desx){
				cout<<f.second<<"\n";
				break;
			}
			else{
				for(int i=0; i<8; i++){
					int ny= yy+dy[i];
					int nx= xx+dx[i];
					if(ny<0||nx<0||ny>=l||nx>=l||visited[ny][nx]) continue;
					visited[ny][nx]=1;
					q.push({{ny,nx},f.second+1});
				}
			}
		}
	}
	
	return 0;
}
