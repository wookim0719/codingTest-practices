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
	// ��� ������ �Է¹ް� �ִ��� �̴´�. 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>> a[i][j];
			if(max<a[i][j])
			max = a[i][j];
		}
	}
	//max���� �������� ������ �ִ��� ������ ���� ���̸� ã�´�. 
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
