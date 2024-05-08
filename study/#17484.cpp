#include<bits/stdc++.h>
using namespace std;
const int INF= 987654321;
int n,m;
int a[7][7];
int dy[3] ={1,1,1};
int dx[3] = {0,1,-1};
int ret= INF;


void go(int y,int x,int sum, int previous){
	if(y==n-1){
		ret= min(sum,ret);
		return;
	}
	for(int i=0; i<3; i++){
		if(previous==i) continue;
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m) continue;
		go(ny,nx,sum+a[ny][nx],i);
	}
	return;
}


int main(){
	cin>>n>>m;
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<m; i++){
		go(0,i,a[0][i],-1);
	}
	
	cout<<ret;
	return 0;
}
