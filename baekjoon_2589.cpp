#include <bits/stdc++.h>
using namespace std;
int n,m;
int ret, max_value;
char a[51][51];
int visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
    

int bfs(int y, int x){
	int ret=0;
	queue<pair<int, int>> q;
	visited[y][x]=1;
	q.push({y,x});
	while(q.size()){
		pair<int,int> here = q.front(); q.pop();
        for(int i=0; i<4; i++){
        	int ny= dy[i] + here.first;
        	int nx= dx[i] + here.second;
        	if(nx<0||ny<0||ny>=n||nx>=m||visited[ny][nx]||a[ny][nx]=='W') continue;
        	else{	
        			visited[ny][nx] = visited[here.first][here.second]+1;
        			q.push({ny,nx});
        			ret = max(ret, visited[ny][nx]); 
			}
        }
	}
	return ret;	
} 

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>> a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//vissited를 초기화
   			 memset(visited, 0, sizeof(visited)); 
			if(a[i][j]=='L'){
			int a = bfs(i,j);
			max_value= max(max_value,a);
			}
		}
	}
	if(max_value>0)
	cout<< max_value-1;
	return 0;
}
