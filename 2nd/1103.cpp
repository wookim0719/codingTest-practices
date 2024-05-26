#include<bits/stdc++.h>
using namespace std;
const int INF= 987654321;
int n,m;
int a[51][51];
int visited[51][51];
int dp[51][51];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
string temp;
int go(int y, int x){
	if(y<0||x<0||y>=n||x>=m||a[y][x]==-1){
		return 0;
	}
	else if(visited[y][x]>1){
		cout<<-1<<"\n";
		exit(0);
	}
	int &ret= dp[y][x];
	if(ret) {
		cout<<y<<" "<<x<<'\n';
		return ret;}
	
	int mm= a[y][x];
	for(int i=0; i<4; i++){
		int ny= y+dy[i]*mm;
		int nx= x+dx[i]*mm;
			visited[ny][nx]++;
			ret = max(ret,go(ny,nx)+1);
			visited[ny][nx]--;		
	}
	return ret;
}

int main(){
	cin>>n>>m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<n; i++){
		cin>>temp;
		for(int j=0; j<m; j++){
			if(temp[j]=='H') a[i][j]=-1;
			else
			a[i][j]=temp[j]-'0';
	}
		}
	visited[0][0]=1;
	int b= go(0,0);
	

	cout<<b;
	
	return 0;
}
