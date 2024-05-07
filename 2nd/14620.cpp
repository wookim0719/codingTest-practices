#include<bits/stdc++.h>
using namespace std;
int n;
int a[11][11];
int dx[4]= {1,0,-1,0};
int dy[4]= {0,-1,0,1};
int visited[11][11];
int ret =987654321;

bool check(int y, int x){
	bool flag =true;
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=n||visited[ny][nx]||visited[y][x]) flag = false;
	}
	return flag;
}

int calculate(int y, int x){
	int value =a[y][x];
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		value += a[ny][nx];
		
	}
	return value;
}
void visit(int y, int x){
	visited[y][x]=1;
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		visited[ny][nx]=1;
	}
	return;
}
void rewind(int y, int x){
	visited[y][x]=0;
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		visited[ny][nx]=0;
	}
	return;
}

void go(int cnt, int cost){
	if(cnt==3) {
		ret = min(ret,cost);
		return ;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(check(i,j)){
				visit(i,j);
				go(cnt+1,cost+calculate(i,j));
				rewind(i,j);
			}
		}
	}
	
	
	
	return ;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	go(0, 0);
	cout<<ret;
	return 0;
}
