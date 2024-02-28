#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char a[6][6];
int visited[6][6];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt = 0;

void dfs(int y, int x, int num){
	if(y==0& x==m-1){
		if(num == k) cnt++;
		return ;
	}
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||ny>=n||nx>=m||nx<0||visited[ny][nx]) continue;
		visited[ny][nx]=1;
		dfs(ny,nx, num+1);
		visited[ny][nx]=0;
	}
}

int main(){
	cin>>n>>m>>k;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]=='T')
				visited[i][j] =1;
		}
	}
	visited[n-1][0] = 1;
	
	dfs(n-1,0,1);
	
	cout<< cnt;
	
	
	return 0;
}
