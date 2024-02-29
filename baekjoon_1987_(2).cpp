#include<bits/stdc++.h>
using namespace std;
int R,C;
int ret;
char a[21][21];
int ny,nx;
int vistited[21][21];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void go(int y, int x, int num, int cnt){
	ret = max(ret, cnt);
	for(int i=0; i<4; i++){
		       ny = y + dy[i], nx = x + dx[i];

	  if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int _next = (1 << (int)(a[ny][nx] - 'A'));
        if((num & _next) == 0) go(ny, nx, num | _next, cnt + 1);
	}
	return;
}
int main(){
	cin>>R>>C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>> a[i][j];
		}
	}
	
	go(0,0,1<< (int)(a[0][0]- 'A'),1);
	cout<<ret;
	
	return 0;
}
