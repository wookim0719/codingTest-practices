#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[30];
char a[21][21];
int visited[21][21];
int dy[4] = {-1,0,1,0};
int dx[4] = { 0,1,0,-1};
int ret;
int x,y;
int max_num;

void dfs(int y, int x,int cnt){
	ret = max(ret, cnt);
	for(int i=0; i<4; i++){
		int ny= dy[i]+ y;
		int nx= dx[i]+ x;
		if(ny<0||nx<0||nx>=m||ny>=n||visited[ny][nx]||b[a[ny][nx]-65])continue;
		b[a[ny][nx]-65]=1;
		visited[ny][nx] =1;
		dfs(ny,nx,cnt+1);
		visited[ny][nx] = 0;
		b[a[ny][nx]-65] =0;
   }
   return ;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>> a[i][j];
		}
	}
	b[a[0][0]-65] =1;
	visited[0][0] = 1;
	dfs(0,0,1);
//	queue<pair<int,int>> q;
//	q.push({0,0});
//	while(q.size()){
//		tie(y,x) = q.front(); 
//		q.pop();
//		for(int i=0; i<4; i++){
//			int ny= dy[i]+ y;
//			int nx= dx[i]+ x;
//			if(ny<0||nx<0||nx>=m||ny>=n||visited[ny][nx]||b[a[ny][nx]-65])continue;
//				b[a[ny][nx]-65]=1;
//				cout<<ny<<" "<<nx<<"\n";
//				visited[ny][nx] = visited[y][x]+1;
//				max_num= max(visited[ny][nx], max_num);
//				q.push({ny,nx});
//		}
//	}
	
	cout<<ret;
	
	return 0;
}

