#include <bits/stdc++.h>
using namespace std;

int n,m;
const int max_v = 1501;
char a[max_v][max_v];
int visited[max_v][max_v];
int visited_swan[max_v][max_v];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
pair<int,int> b;
queue<pair<int,int>> waterQ, water_tempQ, swanQ, swan_tempQ;
int cnt;
int y,x;

//void find(int y, int x){
//	visited[y][x] =1;
//	for(int i=0; i<4; i++){
//			int ny = dy[i] + y;
//			int nx = dx[i] + x;
//			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]=='X'||visited[ny][nx]) continue;
//			if(a[ny][nx] == '.') {
//			find(ny,nx);
//			}
//			if(a[ny][nx] == 'L') flag = 1;
//		}
//		return ;
//}
//
//void dfs(int y,int x){
//	for(int i=0; i<4; i++){
//		int ny = dy[i] + y;
//		int nx = dx[i] + x;
//		if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]=='.') continue;
//		if(a[ny][nx] == 'X') willMelt.push_back({ny,nx});
//	}
//	return ;
//}

bool move_swan(){
	while(swanQ.size()){
		tie(y,x) = swanQ.front();
		swanQ.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if(ny<0||nx<0||ny>=n||nx>=m||visited_swan[ny][nx]) continue;
			visited_swan[ny][nx] =1;
			if(a[ny][nx] == '.')swanQ.push({ny, nx});
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(a[ny][nx] == 'L') return true;
		}
	}
	return false;
}

void water_melting(){
	while(waterQ.size()){
		tie(y,x) = waterQ.front();
		waterQ.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]) continue;
			if(a[ny][nx] == 'X'){
			visited[ny][nx]=1;
			water_tempQ.push({ny,nx});
			a[ny][nx] = '.';
	}
			
		}
	}
	
}

void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
}  

int main(){
	cin>> n>> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>> a[i][j];
			if(a[i][j] == 'L')
			 b = {i,j};
			if(a[i][j] == '.' || a[i][j] == 'L') {
				visited[i][j] =1; 
				waterQ.push({i,j});
			}
		}
	}
	swanQ.push({b.first,b.second});
	visited_swan[b.first][b.second] =1;
	
	while(true){
		if(move_swan()) break;
		water_melting();		
		waterQ= water_tempQ;
		swanQ = swan_tempQ;
		Qclear(water_tempQ);
		Qclear(swan_tempQ);	
		cnt++;
	}
	

	cout<< cnt;
	
	return 0;
}



