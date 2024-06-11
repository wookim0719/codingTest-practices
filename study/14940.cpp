#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
int visited[1001][1001];
queue<pair<int,int>> q;
pair<int,int> st;
int dy[4]= {-1,0,1,0};
int dx[4]= {0,1,0,-1};

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]==2){
				st.first=i;
				st.second= j;
				visited[i][j]=1;
			}
		}
	}
	q.push({st.first,st.second});
	
	while(q.size()){
		int y= q.front().first;
		int x= q.front().second;
		q.pop();
		for(int i=0;i<4; i++){
			int ny= y+dy[i];
			int nx= x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]||a[ny][nx]==0) continue;
			visited[ny][nx] = visited[y][x]+1;
			q.push({ny,nx});
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j])
			cout<<visited[i][j]-1<<" ";
			else if(a[i][j]==0)
			cout<<0<<" ";
			else
			cout<<-1<<" ";
		}
		cout<<"\n";
		}
	
	
	return 0;
}
