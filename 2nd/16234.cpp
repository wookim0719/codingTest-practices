#include<bits/stdc++.h>
using namespace std;
int dy[4]= {-1,0,1,0};
int dx[4]= {0,1,0,-1};
int n,l,r,cnt;
int a[51][51];
int visited[51][51];
vector<pair<int,int>> temp;
int flag=0;


void dfs(int y,int x){
	visited[y][x]=1;
	temp.push_back({y,x});
	for(int i=0;i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]) continue;
		int diff = abs(a[ny][nx]-a[y][x]);
		if(diff>=l&&diff<=r){
			flag=1;
			dfs(ny,nx);
		}
	}	
}

void calculate(){
	int sum=0;
	for(auto i: temp){
		sum+= a[i.first][i.second];
	}
	sum /= temp.size();
	for(auto i:temp){
		a[i.first][i.second] = sum;
	}
}


int main(){
	cin>>n>>l>>r;
	
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	while(true){
	flag=0;	
	//visited배열 초기화
	memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				temp.clear();
				dfs(i,j);
				calculate();
			}
		}
	}
	if(flag==0) break;
	else
	cnt++;
}

	cout<<cnt;
	return 0;
}
