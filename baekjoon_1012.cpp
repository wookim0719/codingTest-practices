#include <bits/stdc++.h>
using namespace std;
int num;
int m,n,k;
const int max_length = 54;
int a[max_length][max_length];
int visited[max_length][max_length];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void go(int y, int x){
	visited[y][x] =1;
	// 하나씩 방문해 보면서 들어갈 수 있으면 진입한다.  
	for(int i=0; i<4; i++){
	int	ny= y+ dy[i];
	int	nx= x+ dx[i];
		if(nx<0||ny<0||nx>m||ny>n) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx]) go(ny,nx);
	}
	
}
int main(){
	cin >>num;
	while(num){
	int cnt =0;
	// 가로는 m, 세로는 n, 배추 갯수 k개  
	cin>> m>>n>>k;
	// 행렬에 해당 값들을 저장해준다.  
	for(int i=0; i<k; i++){
		int tempx,tempy;
		cin>> tempx>> tempy;
		a[tempy][tempx]=1;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j] && a[i][j]){
				go(i,j);
				cnt ++;
			
			}	
		}
	}
	fill(&a[0][0], &a[0][0]+51*51,0);
	fill(&visited[0][0], &visited[0][0]+51*51,0);
	cout<< cnt<< "\n";
	
	num--;
}
    return 0;
}
