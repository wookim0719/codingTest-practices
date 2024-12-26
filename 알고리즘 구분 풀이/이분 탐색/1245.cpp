#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101][101];
int visited[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ddy[8] = {-1,0,1,0,-1,-1,1,1};
int ddx[8] = {0,1,0,-1,1,-1,-1,1};
vector<pair<int,int>> temp;
int ret;

void go(int y,int x){
	visited[y][x]=1;
	for(int i=0; i<8; i++){
		int ny= y+ddy[i];
		int nx= x+ddx[i];
		if(ny>=n||nx>=m||ny<0||nx<0||visited[ny][nx]) continue;
		if(a[ny][nx]==a[y][x]){
			temp.push_back({ny,nx});
			go(ny,nx);	
		}
	}
	return;
}

bool check(){
	int cnt=0;
	for(int i=0; i<temp.size(); i++){
		int y= temp[i].first;
		int x= temp[i].second;
		int value = a[y][x];
		if(value==0)return false;
		for(int i=0; i<8; i++){
			int ny= y+ddy[i];
			int nx= x+ddx[i];
			if(ny>=n||nx>=m||ny<0||nx<0) continue;
			if(a[ny][nx]>value) return false;
			if(a[ny][nx]<value)
			cnt++;
		}
	}
	if(cnt==0)return false;
	else
	return true;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j]){
				temp.clear();
				temp.push_back({i,j});
				go(i,j);
				if(check()){
				//	cout<<i<<" "<<j<<"\n";
				
					ret++;
				}
			}
		}
	}
	cout<<ret;
	return 0;
}
