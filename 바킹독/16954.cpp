#include<bits/stdc++.h>
using namespace std;
char a[8][8];
vector<pair<int,int>> wall;
vector<pair<int,int>> t_wall;
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int dx[9]={0,0,1,1,1,0,-1,-1,-1};
int visited[8][8];
int walls[8][8];
int y,x;
int main(){
	
	for(int i=0; i<8; i++){
		string temp;
		cin>>temp;
		for(int j=0; j<8; j++){
			a[i][j]= temp[j];
			if(a[i][j]=='#'){
				walls[i][j]=1;
				walls[i+1][j]=1;
				wall.push_back({i,j});
			} 
		}
	}
	y=7;
	x=0;
	queue<pair<int,int>> q;
	queue<pair<int,int>> q2;
	q.push({y,x});
	bool flag= false;
	while(true){
	//벽의 위치를 미리 예상하고 상욱이를 움직인다.
	memset(visited,0,sizeof(visited));
	while(q.size()){
		auto f= q.front();
		if(f.first==0&&f.second==7){
			flag=true;
			break;
		}
		q.pop();
		for(int i=0; i<9; i++){
			int ny= f.first+dy[i];
			int nx= f.second+dx[i];
			if(ny<0||nx<0||ny>=8||nx>=8||walls[ny][nx]||visited[ny][nx])continue;
		//	cout<<ny<<" "<<nx<<"\n";
			visited[ny][nx]=1;
			q2.push({ny,nx});
		}		
	}
	if(q2.size()==0)break;
	if(flag)break;
	// q에 q2를  복사해준다. 
	while(q2.size()){
		auto f=q2.front();
		q.push(f);
		q2.pop();
	}
	memset(walls,0,sizeof(walls)); 
	//벽을 움직인다.
	for(int i=0; i<wall.size(); i++){
		int t1= wall[i].first;
		int t2= wall[i].second;
		if(t1+1<=7){
			walls[t1+1][t2]=1;
			if(t1+2<=7)
			walls[t1+2][t2]=1;
		}
		t_wall.push_back({t1+1,t2});
	}
	wall.clear();
	wall=t_wall;
	t_wall.clear();
	} 
	
	if(flag) cout<<1;
	else cout<<0;
	return 0;
}
