#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
int visited[1001][1001][2];
int dy[4] ={-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ret=987654321;
struct v{
	int y,x,crash,cnt;
};
queue<v> q;


int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		for(int j=0; j<m; j++){
			a[i][j]=temp[j]-'0';
		}
	}
	visited[0][0][0]=1;
	v temp;
	temp.y=0; temp.x=0; temp.cnt=0; temp.crash=0;
	q.push(temp);
	
	while(q.size()){
		v f = q.front();
		if(f.y==n-1&&f.x==m-1){
			ret= min(ret, f.cnt);
		}
		q.pop();
		for(int i=0; i<4; i++){
			int nx= f.x+dx[i];
			int ny= f.y+dy[i];	
	if(nx<0||ny<0||nx>=m||ny>=n||visited[ny][nx][f.crash]||(a[ny][nx]==1&&f.crash==1))continue;
		if(a[ny][nx]==0){
			visited[ny][nx][f.crash]=1;
			v temp2;
			temp2.y=ny; temp2.x=nx; temp2.cnt=f.cnt+1; temp2.crash=f.crash;
			q.push(temp2);
		}
		else{
		visited[ny][nx][1]=1;
			v temp2;
			temp2.y=ny; temp2.x=nx; temp2.cnt=f.cnt+1; temp2.crash=1;
			q.push(temp2);
		}
		}	
	}
	if(ret==987654321) cout<<-1;
	else
	cout<<ret+1;
	return 0;
}
