#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[51][51];
int visited[51][51];
int cnt;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int compSize[2504];
int mx, big;

int dfs(int y, int x, int cnt){
	if(visited[y][x]) return 0;
	visited[y][x] = cnt;
	int ret =1;
	for(int i=0; i<4; i++){
		if(!(a[y][x] & (1<<i))){
		int ny= y +dy[i];
		int nx =x + dx[i];	
		ret += dfs(ny,nx, cnt);
		}
	}
	return ret;
}

int main(){
	cin>>m>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>> a[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j]){
			cnt++;
			compSize[cnt]=dfs(i,j,cnt);
			mx = max(mx, compSize[cnt]);
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i+1<n){
				int a= visited[i+1][j];
				int b= visited[i][j];
				if(a!=b){
					big = max(big, compSize[a]+compSize[b]);
				}
			}
			if(j+1<m){
					int a= visited[i][j+1];
				int b= visited[i][j];
				if(a!=b){
					big = max(big, compSize[a]+compSize[b]);
				}
			}
		}
	}
	cout<<cnt<< "\n"<< mx<< "\n"<< big<< "\n";
	
	
	return 0;
}
