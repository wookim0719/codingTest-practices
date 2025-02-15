#include<bits/stdc++.h>
using namespace std;
int n;
char a[1001][1001];
queue<pair<int,int>> f;
queue<pair<int,int>> l;
queue<pair<int,int>> ql;
queue<pair<int,int>> qf;
int visited[1001][1001];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int r,c;
bool flag= false;

void move_f(){
	while(f.size()){
		auto i = f.front();
		int y= i.first;
		int x= i.second;
		f.pop();
		for(int i=0; i<4; i++){
			int ny= y+dy[i];
			int nx= x+dx[i];
			if(ny<0||nx<0||ny>=r||nx>=c||a[ny][nx]=='*'||a[ny][nx]=='#') continue;
			a[ny][nx] = '*';
			qf.push({ny,nx});
		}
	}
	while(qf.size()){
		auto ff= qf.front();
		f.push(ff);
		qf.pop();
	}
	return;
}

void move_l(){
	while(l.size()){
		auto i = l.front();
		int y= i.first;
		int x= i.second;
	//	cout<<y<<" "<<x<<"\n";
		l.pop();
		for(int i=0; i<4; i++){
			int ny= y+dy[i];
			int nx= x+dx[i];
			if(ny<0||nx<0||ny>=r||nx>=c){
				flag= true;
			}
			else{
				if(visited[ny][nx]||a[ny][nx]=='#'||a[ny][nx]=='*')continue;
				else{
					visited[ny][nx]=1;
					ql.push({ny,nx});
				}
			} 
		}
	}
	while(ql.size()){
		auto ff= ql.front();
		ql.pop();
		l.push(ff);
	}
	return;
}
 
int main(){
	cin>>n;
	
	while(n--){
		flag= false;
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));

		cin>>c>>r;
		while(l.size()){
			l.pop();
		}
		while(f.size()){
			f.pop();
		}
		for(int i=0; i<r; i++){
			string temp;
			cin>>temp;
			for(int j=0; j<c; j++){
				a[i][j]= temp[j];
				if(a[i][j]=='*'){
					f.push({i,j});
				}
				if(a[i][j]=='@'){
					l.push({i,j});	
				}
			}
		}
		int ret=0;
		while(true){
			if(l.size()==0) {
				ret=-1;
				break;
			};
			move_f();
			move_l();
			ret++;
			if(flag) break;	
		}	 
		if(ret!=-1)
		cout<<ret<<"\n";
		else{
			cout<<"IMPOSSIBLE"<<"\n";
		}
	}	
	
	return 0;
}
