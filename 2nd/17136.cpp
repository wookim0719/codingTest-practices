#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int ret= 987654321;
int visited[10][10];
int mp[6];
vector<pair<int,int>> v;

bool possible(int y, int x, int num){
	if (y + num > 10 || x + num > 10) return false;  // 경계 체크
	bool flag= true;
	for(int i=y; i<y+num; i++){
		for(int j=x; j<x+num; j++){
			if(a[i][j]==0||visited[i][j]) 
			{
			return false;	
			}
		}
	}
	return true;
}

void go(int num, int cnt){
	if(cnt>=ret) return;
	if(num==v.size()) {
		//cout<<cnt;
		bool flag= true;
		for(auto i: v){
			if(!visited[i.first][i.second]) flag= false; 
		}
		if(flag)
		ret = min(ret, cnt);
		return;
	}
	if(visited[v[num].first][v[num].second]) {
		go(num+1,cnt);
		return;
	}
	for(int i=5; i>=1; i--){
		if(mp[i]&&possible(v[num].first,v[num].second,i)){
			// 1로 채워주기 
			for(int j=v[num].first; j<v[num].first+i; j++){
				for(int k=v[num].second; k<v[num].second+i; k++){
					visited[j][k]=1;
				}
			} 
			mp[i]--;
			go(num+1, cnt+1);
			mp[i]++;
			for(int j=v[num].first; j<v[num].first+i; j++){
				for(int k=v[num].second; k<v[num].second+i; k++){
					visited[j][k]=0;
				}
			} 
		// 다시 0으로 채워주기  
		} 
	}	
	return;	
}

int main(){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin>>a[i][j];
			if(a[i][j]) 
			v.push_back({i,j});
		}
	}
	for(int i=1; i<=5; i++){
		mp[i]=5;
	}

	go(0,0);
	if(ret==987654321) cout<<-1;
	else
	cout<<ret;
	
	return 0;
}
