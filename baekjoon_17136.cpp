#include<bits/stdc++.h>
using namespace std;
int a[104][104];
map<int,int> mp;  
const int INF= 987654321;
int n=10;
int ret = INF;

bool check(int y, int x, int cnt){
	if(y+cnt>n || x+cnt>n) return false;
	for(int i=y; i<y+cnt; i++){
		for(int j=x; j<x+cnt; j++){
			if(a[i][j] ==0)
			return false;
		}
	}
	return true;
}

void draw(int y, int x, int cnt, int value){
	for(int i=y; i<y+cnt; i++){
		for(int j=x; j<x+cnt; j++){
			a[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt){
	if(cnt>=ret) return;
	if(x==n) {
		dfs(y+1,0,cnt);
		return;
	}
	if(y==n) {
		ret = min(cnt,ret);
		return;
	}
	if(a[y][x] == 0){
		dfs(y,x+1,cnt); return;
	}
	for(int _size = 5; _size>=1;_size--){
		// 큰 거부터 찾는다.  
		if(mp[_size]==5)continue;
	 	if(check(y,x,_size)){
	 		mp[_size]++;
	 		draw(y,x,_size,0);
	 		dfs(y,x+_size,cnt+1);
	 		draw(y,x,_size,1);
	 		mp[_size]--;
		 } 
	}
	return ;
}


int main(){
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin>>a[i][j];
			
		}
	}
	
	dfs(0,0,0);
	cout << (ret == INF ? -1 : ret) << "\n"; 
	
	return 0;
}
