#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1001][1001];
int visited[1001][1001];
vector<pair<int,int>> t;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};
int ret;

void go(int y,int x){
	//cout<<y<<" "<<x<<"\n";
	char temp = a[y][x];
	if(temp=='D'){
		y+=1;
	}
	else if(temp=='L'){
		x-=1;
	}
	else if(temp=='R'){
		x+=1;
	}
	else y-=1;
	//cout<<temp<<" "<<y<<" "<<x<<"\n";
	if(!visited[y][x]){
		visited[y][x]=ret;
	//	cout<<y<<" "<<x<<"\n";
		t.push_back({y,x});
		go(y,x);	
	}
	else{
	//	cout<<y<<" "<<x<<" "<<visited[y][x]<<" "<<ret<<"\n";
		if(visited[y][x]<(ret)){
			ret--;
		}
		for(auto i: t){
			visited[i.first][i.second] = visited[y][x];
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char temp;
			cin>>temp;
			a[i][j]=temp;
		}
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j]){
				ret++;
				t.clear();
				t.push_back({i,j});
				visited[i][j]=ret;
		//		cout<<i<<" "<<j<<"\n";
				go(i,j);
			}
		}
	}
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout<<visited[i][j];
//		}
//		cout<<"\n";
//	}
	cout<<ret;
	return 0;
}
