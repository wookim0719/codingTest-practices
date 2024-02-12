#include <bits/stdc++.h>
using namespace std;
int n;
const int max_n =101;
int a[max_n][max_n];
int visited[max_n][max_n];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int output = 1;

void go(int y, int x,int max){
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
	int ny= y+dy[i];
	int nx= x+dx[i];
		if(ny<0|| nx<0|| ny>n|| nx>n) continue;
		if(a[ny][nx]>max && !visited[ny][nx])
			go(ny,nx,max);
	}
	return;
}
int main(){
	int max = 0;
	cin>> n;
	// 행렬 값들을 입력받고 최댓값을 뽑는다. 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>> a[i][j];
			if(max<a[i][j])
			max = a[i][j];
		}
	}
	//max값을 기준으로 돌려서 최댓값을 가지는 물의 높이를 찾는다. 
	while(max>0){
		int cnt =0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(a[i][j]>max && !visited[i][j]){
					go(i,j,max);
					cnt++;
				} 
			}
		}
		fill(&visited[0][0], &visited[0][0]+101*101,0);
		if(cnt>output) output = cnt;
		max--;
}
	cout<< output; 
	return 0;
	
}
