#include<bits/stdc++.h>
using namespace std;
int a[10][10], visited[10][10];
int n,m,ret;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
vector<pair<int, int>> virusList, wallList;

void dfs(int first,int second){
	visited[first][second] =1;
	for(int i=0; i<4; i++){
		int ny = first+dy[i];
		int nx = second+dx[i];
		if(nx<0||nx>=m||ny<0||ny>=n||visited[ny][nx]==1||a[ny][nx]) continue;
		dfs(ny,nx);	
	}
	return;
}

int solve(){
	fill(&visited[0][0], &visited[0][0] +10 *10,0);
	for(pair<int, int> b: virusList){
		visited[b.first][b.second] =1;
		dfs(b.first, b.second);
	}
	
	int cnt =0;
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(a[i][j] ==0 && visited[i][j]!=1)cnt++;
		}
	}
	
	return cnt;
	}
	



int main(){
	cin>> n>> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			if(a[i][j]== 0)
				wallList.push_back({i,j});
			if(a[i][j]==2)
				virusList.push_back({i,j});
		}
	}
	
	for(int i=0; i<wallList.size(); i++){
		for(int j=0; j<i; j++){
			for(int k=0; k<j; k++){
				a[wallList[i].first][wallList[i].second] =1;
				a[wallList[j].first][wallList[j].second] =1;
				a[wallList[k].first][wallList[k].second] =1;
				ret = max(ret, solve());
				a[wallList[i].first][wallList[i].second] =0;
				a[wallList[j].first][wallList[j].second] =0;
				a[wallList[k].first][wallList[k].second] =0;
			}
		}
	}
	
	cout<<ret<<"\n";
	
	return 0;
}
