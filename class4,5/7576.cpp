#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
int visited[1001][1001];
int ret;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
struct to{
	int y,x,cnt;
};
queue<to> q;

int main(){
	cin>>m>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];		
			if(a[i][j]==1){
				visited[i][j]=1;
				to tmp;
				tmp.y= i; tmp.x=j; tmp.cnt=0;
				q.push(tmp);
			}
		}
	}	
	
	while(q.size()){
		auto f= q.front();
		ret= max(ret, f.cnt);
		q.pop();
		for(int i=0; i<4; i++){
			int ny= f.y+dy[i];
			int nx= f.x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]||a[ny][nx]!=0) continue;
			visited[ny][nx]=1;
			a[ny][nx]=1;
			to tmp2;
			tmp2.y= ny; tmp2.x=nx; tmp2.cnt= f.cnt+1;
			q.push(tmp2);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
	//		cout<<a[i][j];
			if(a[i][j]==0)
			ret=-1;
		}
	//	cout<<"\n";
	}
	cout<<ret;
	
	return 0;
}
