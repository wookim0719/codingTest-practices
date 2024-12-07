#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101][101];
int isAir[101][101];
int dy[4]= {-1,0,1,0};
int dx[4]= {0,1,0,-1};
vector<pair<int,int>> cheese;
	vector<pair<int,int>> temp;
	vector<pair<int,int>> temp2;
int ret;

void go(int y,int x){
	for(int i=0; i<4; i++){
		int ny= dy[i]+y;
		int nx= dx[i]+x;
		if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]||isAir[ny][nx]) continue;
		isAir[ny][nx]=1;
		go(ny,nx);
	}
	return;
}
void check(){
	temp.clear();
	temp2.clear();
	for(int i=0; i<cheese.size(); i++){
		int y= cheese[i].first;
		int x= cheese[i].second;
		int cnt=0;
		for(int j=0; j<4; j++){
			int ny = y+dy[j];
			int nx = x+dx[j];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]||!isAir[ny][nx]) continue;
			cnt++;
		}
		if(cnt<2) {
			temp.push_back({y,x});
		}
		else{
			temp2.push_back({y,x});
		}
	}
	for(auto k: temp2){
		a[k.first][k.second]=0;
		isAir[k.first][k.second]=1;
		go(k.first,k.second);
	}
	cheese = temp;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]){
				cheese.push_back({i,j});
			}
		}
	}
	isAir[0][0]=1;
	go(0,0);
	if(cheese.size()==0){
		cout<<0;
	}
	else{
		while(true){
			if(cheese.size()==0) break;
			check();
		//	go(0,0);
			ret++;
//			for(int i=0; i<n; i++){
//				for(int j=0; j<m; j++){
//					cout<<a[i][j]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n";
//			for(int i=0; i<n; i++){
//				for(int j=0; j<m; j++){
//					cout<<isAir[i][j]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n";
		}
		cout<<ret;
	}
	return 0;
}
