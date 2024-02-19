#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101][101], visited[101][101];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,-0,-1};
vector<pair<int, int>> melted;
int cnt;
int cnt2;

void melt(int y, int x){
	visited[y][x] = 1;
	if(a[y][x] == 1){
		melted.push_back({y,x});
		return;
	}
	for(int i=0; i<4; i++){
		int ny = dy[i]+y;
		int nx = dx[i]+x;
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue; 
        melt(ny,nx);
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];			
		}
	}
	
	while(true){
		fill(&visited[0][0], &visited[0][0]+ 101*101, 0);
		melted.clear();
		melt(0,0);
		cnt2= melted.size();
		for(auto it: melted){
			a[it.first][it.second] = 0;
		}
		bool flag = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j] == 1 ) flag = 1;
			}
		}
		cnt++;
		if(flag ==0) break;
	}
	
	cout<< cnt<< "\n"<< cnt2;
	return 0;
}
