#include<bits/stdc++.h>
using namespace std;
int a[301][301];
int a2[301][301];
int visited[301][301];
int n,m;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> q2;
int ret;

void count(int y,int x){
	for(int i=0; i<4; i++){
		int ny= dy[i]+y;
		int nx= dx[i]+x;
	//	cout<<ny<<" "<<nx<<"\n";
		if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==0||visited[ny][nx]) continue;
		visited[ny][nx]=1;
		count(ny,nx);
	}
}

void go(int y, int x){
	int cnt=0;
	for(int i=0; i<4; i++){
		int ny= dy[i]+y;
		int nx= dx[i]+x;
		if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]!=0) continue;
		cnt++;	
	}
	a2[y][x]= a[y][x]-cnt;
	if(a2[y][x]<=0){
		a2[y][x]=0;
	}
	else{
		q2.push({y,x});
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	queue<pair<int,int>> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]){
				q.push({i,j});
			}
		}
	}
	int cnt=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j]!=0&&!visited[i][j]){
					visited[i][j]=1;
					count(i,j);
					cnt++;
				}
			}
		}
	
	while(true){
		memset(visited,0,sizeof(visited));
		int cnt2=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j]!=0&&!visited[i][j]){
					visited[i][j]=1;
					count(i,j);
					cnt2++;
				}
			}
		}
		if(cnt!=cnt2){
			if(cnt2!=0)
			cout<<ret;
			else cout<<0;
			break;
		}

		while(q.size()){
			auto f= q.front();
			q.pop();
			go(f.first,f.second);
		}
		while(q2.size()){
			auto f2= q2.front();
			q2.pop();
			q.push(f2);
		}
		memcpy(a,a2,sizeof(a2));
		ret++;
	}
	
	//cout<<ret;
	return 0;
}
