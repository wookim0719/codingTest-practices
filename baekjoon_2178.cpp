#include <bits/stdc++.h>
using namespace std;
int n,m;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
const int max_a = 104;
string input[max_a];
//입력받을 map을 저장할 공간  
int a[max_a][max_a];
//방문했는지 확인하는 행렬  
int visited[max_a][max_a];

void go(int y, int x){
	// 큐 선언  
	queue<pair<int,int>> q;
	visited[y][x] = 1;
	q.push({y,x});
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0 || nx<0 || ny>n || nx >m) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx]) {
			visited[ny][nx] = visited[y][x] +1;
			q.push({ny,nx});
		}
	}
}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>> input[i];
	}
	//map에 해당되는 값들 저장하기 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a[i][j] = (int)input[i][j]-48;
		}
	}
	
	
	go(0,0);
	
	cout<<visited[n-1][m-1];
	
	return 0;
	
} 
