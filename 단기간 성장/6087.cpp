#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> tt;
const int INF = 987654321;
char a[100][100];
int visited[100][100][4];
int n,m;
int dy[4]= {-1,1,0,0};
int dx[4]= {0,0,1,-1};
int ret=INF;
vector<pair<int,int>> v;
struct laser{
	int y,x,cnt,dir;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++){
		string temp;
		cin>>temp;
		for(int j=0; j<n; j++){
			a[i][j]=temp[j];
			if(a[i][j]=='C'){
				v.push_back({i,j});	
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
		fill(visited[i][j],visited[i][j]+4,INF);
	}
	for(int i=0; i<4; i++)
	visited[v[0].first][v[0].second][i]=0;
	queue<pair<pair<int,int>,pair<int,int>>> q;
//	temp.y=v[0].first;
//	temp.x=v[0].second;
//	temp.dir= -1;
//	temp.cnt=0;
	q.push({{v[0].first,v[0].second},{-1,0}});
	//go(v[0].first,v[0].second,-1,0);
	while(q.size()){
		auto f= q.front();
		int cnt= f.second.second;
		int y = f.first.first;
		int x= f.first.second;
		int dir= f.second.first;
		if(y==v[1].first&&x==v[1].second){
			ret= min(ret,cnt);
		}
		q.pop();
		for(int i=0; i<4; i++){
			int nx= x+dx[i];
			int ny= y+dy[i];
			int ccnt= cnt;
			if(dir!=i&&dir!=-1){
				ccnt++;
			}
			if(ny<0||nx<0||ny>=m||nx>=n||visited[ny][nx][i]<=ccnt||a[ny][nx]=='*') continue;
			else{
			//	laser temp2;
				visited[ny][nx][i]=ccnt;	
				q.push({{ny,nx},{i,ccnt}});
			}
		}
	}
	cout<<ret;
	
	return 0;
}
