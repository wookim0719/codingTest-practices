#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501][501];
int visited[501][501];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int maxr;
int res;

int go(int y, int x,int cnt){
	queue<pair<int,int>> q;
	q.push({y,x});
	while(q.size()){
			y = q.front().first;
			x= q.front().second;
			q.pop();
		for(int i=0; i<4; i++){
			int ny = y+dy[i];
			int nx= x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==0||visited[ny][nx]) continue;
			else{
				visited[ny][nx]=1;
				cnt++;
				q.push({ny,nx});
			}
		}
}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<n ;i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j]&&a[i][j]){
				visited[i][j]=1;
				maxr = max(maxr,go(i,j,1));
				res++;
			}
		}
	}
	
	cout<<res<<"\n"<<maxr;
	return 0;
}
