#include<bits/stdc++.h>
using namespace std;
int n,m;
int d,y,x;
int a[51][51];
int ret;
int dy[4]= {-1,0,1,0};
int dx[4]= {0,-1,0,1};


int main(){
	cin>>n>>m;
	cin>>y>>x>>d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	if(d==1) d=3;
	else if(d==3) d=1;
	
	while(true){
//	cout<<d<<" "<<y<<" "<<x<<"\n";
	int cnt=0;
	if(a[y][x]==0){
		a[y][x]=-1;
		ret++;
	}
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]!=0) continue;
		cnt++;
	}
	if(cnt){
		for(int i=1; i<=4; i++){
			int tt= (d+i)%4;
			int ny= y+dy[tt];
			int nx= x+dx[tt];
			if(a[ny][nx]==0){
				d=tt;
				y+= dy[d];
				x+= dx[d];
				break;
			}
		}
	}
	else{
		int ny= y-dy[d];
		int nx= x-dx[d];
		if(a[ny][nx]==1){
			cout<<ret;
			break;
		}
		else{
			y=ny;
			x=nx;
		}
	}
	}
	
	
	return 0;
}
