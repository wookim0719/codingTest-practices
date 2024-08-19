#include<bits/stdc++.h>
using namespace std;
int n;
int ret1;
int ret2;
char a[101][101];
int visited[101][101];
int dy[4]= {-1,0,1,0};
int dx[4]= {0,1,0,-1};
int visited2[101][101];

void go(int y,int x){
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]||a[ny][nx]!=a[y][x]) continue;
		visited[ny][nx]=1;
		go(ny,nx);
	}
	return;	
}
void go2(int y,int x){
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||visited2[ny][nx]) continue;
		if(a[ny][nx]== 'B'&& a[ny][nx]== a[y][x]){
			visited2[ny][nx]=1;
			go2(ny,nx);
		}
		if(a[y][x]== 'G'&& a[ny][nx]!= 'B'){
			visited2[ny][nx]=1;
			go2(ny,nx);
		}
		if(a[y][x]== 'R'&& a[ny][nx]!= 'B'){
			visited2[ny][nx]=1;
			go2(ny,nx);
		}
	}
	return;	
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				go(i,j);
				ret1++;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited2[i][j]){
				go2(i,j);
				ret2++;
			}
		}
	}
	
	cout<<ret1<<" "<<ret2;
	return 0;
}
