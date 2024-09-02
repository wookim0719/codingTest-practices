#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
int dy[3]={1,0,0};
int dx[3]={0,-1,1};
int visited[1001][1001];
int dp[1001][1001][3];
int ret=-987654321;

int go(int y, int x,int dir){
	if(y==n-1&&x==m-1){
		return a[y][x];
	}
	int &ret = dp[y][x][dir];
	if(ret!=-987654321) return ret;
	for(int i=0; i<3; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(visited[ny][nx]||ny<0||nx<0||ny>=n||nx>=m) continue;
		visited[ny][nx]=1;
		ret = max(ret,a[y][x]+go(ny,nx,i));
		visited[ny][nx]=0;
	}
	return ret;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			dp[i][j][0] = -987654321;
			dp[i][j][1] = -987654321;
			dp[i][j][2] = -987654321;
		}

	visited[0][0]=1;
	int res= go(0,0,0);
	cout<<res;
	return 0;
}
