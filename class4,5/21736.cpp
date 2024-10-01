#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[601][601];
int visited[601][601];
int y,x;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ret;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string t;
		cin>>t;
		for(int j=0; j<m; j++){
			a[i][j]=t[j];
			if(a[i][j]=='I'){
				y= i;
				x= j;
			}
		}
	}
	
	queue<pair<int,int>> q;
	visited[y][x]=1;
	q.push({y,x});
	//cout<<y<<" "<<x<<"\n";
	
	while(q.size()){
		auto f= q.front();
		q.pop();
		//cout<<f.first<<" "<<f.second<<" "<<a[f.first][f.second]<<"\n";
		if(a[f.first][f.second]=='P')ret++;
		for(int i=0; i<4; i++){
			int ny= f.first+dy[i];
			int nx= f.second+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]||a[ny][nx]=='X') continue;
			else{
				visited[ny][nx]=1;
				q.push({ny,nx});
			}
		}
	}
	if(ret==0) cout<<"TT";
	else
	cout<<ret;
	
	
	return 0;
}
