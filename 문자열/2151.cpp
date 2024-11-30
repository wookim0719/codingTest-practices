#include<bits/stdc++.h>
using namespace std;
char a[51][51];
int n;
int dx[4]={-1,-1,1,1};
int dy[4]={1,-1,-1,1};
vector<pair<int,int>> m;
int visited[51][51];
int ret=987654321;


void bfs(int y, int x, int dir, int cnt){
	if(y==m[1].first&&x==m[1].second) {
		ret=min(ret,cnt);
		return;
	}
	for(int i=0; i<4; i++){
		int ny= dy[i]+y;
		int nx= dx[i]+x;
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]||a[ny][nx]=='*') continue;
		visited[ny][nx]=1;
		if(dir!=i)
		dfs(ny,nx,i,cnt+1);
		else
		dfs(ny,nx,i,cnt);
		visited[ny][nx]=0;
	}
	return;	
}



int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j]=='#')
			m.push_back({i,j});
		}
	}
	visited[m[0].first][m[0].second]=1;
	dfs(m[0].first,m[0].second,-1,0);
	
	cout<<ret-1;
	
	return 0;
}
