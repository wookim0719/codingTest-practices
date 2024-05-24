#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[9][9];
int visited[9][9];
vector<pair<int,int>> v;
int ret=987654321;
int dy[4]= {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int,int>> sec={{0,2},{1,3}};

void check(int f, int s, int angle){
	if(a[f][s]==5){
	for(int i=0; i<4; i++){
		int ny= f;
		int nx= s;
		while(true){
			ny+=dy[i];
			nx+=dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==6) break;
			if(a[ny][nx]==0)
			a[ny][nx]=-1;
		}
	}
}
	if(a[f][s]==1){
		int ny= f;
		int nx= s;
		while(true){
			ny += dy[angle];
			nx += dx[angle];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==6) break;
			if(a[ny][nx]==0)
			a[ny][nx]=9;
		}
	}
	if(a[f][s]==2){
		for(int i=0; i<4; i++){
		if(i==angle||i==(angle+2)%4){
		int ny= f;
		int nx= s;
		while(true){
			ny += dy[i];
			nx += dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==6) break;
			if(a[ny][nx]==0)
			a[ny][nx]=-1;
		}
	}
	}
	}
	if(a[f][s]==3){
		for(int i=0; i<4; i++){
		if(i==angle||i==(angle+1)%4){
		int ny= f;
		int nx= s;
		while(true){
			ny += dy[i];
			nx += dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==6) break;
			if(a[ny][nx]==0)
			a[ny][nx]=-1;
		}
}
	}
	}
	
	if(a[f][s]==4){
		for(int i=0; i<4; i++){
		if(i==angle) continue;
		int ny= f;
		int nx= s;
		while(true){
			ny += dy[i];
			nx += dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==6) break;
			if(a[ny][nx]==0)
			a[ny][nx]=-1;
		}
	}
	}
	
	return;
}

void go(int num){
	if(num==v.size()) {
		int cnt=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j]==0) cnt++;
			}
		}
		ret = min(ret, cnt);
		return;
	}
	int temp[9][9];
	memcpy(temp,a,sizeof(a));
	for(int i=0;i<4; i++){
	check(v[num].first,v[num].second,i);
	go(num+1);
	memcpy(a,temp,sizeof(temp));	
	}
	return;
}



int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]!=0&&a[i][j]!=6){
				v.push_back({i,j});
			}
		}
	}
	
	go(0);
	cout<<ret;
	return 0;
}
