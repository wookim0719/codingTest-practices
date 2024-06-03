#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int ret= 987654321;
int mp[6];
vector<pair<int,int>> v;

bool possible(int y, int x, int num, int temp[10][10]){
	    if (y + num > 10 || x + num > 10) return false;  // 경계 체크
	bool flag= true;
	for(int i=y; i<y+num; i++){
		for(int j=x; j<x+num; j++){
			if(temp[i][j]==1) return false;
			if(a[i][j]==0) 
			{
			return false;	
			}
		}
	}
	return true;
}

void go(int num, int cnt, int temp[10][10]){
	if(cnt>=ret) return;
	if(num==v.size()) {
		//cout<<cnt;
		bool flag= true;
		for(auto i: v){
			if(!temp[i.first][i.second]) flag= false; 
		}
		if(flag)
		ret = min(ret, cnt);
		return;
	}
	if(temp[v[num].first][v[num].second]) {
		go(num+1,cnt,temp);
		return;
	}
	for(int i=5; i>=1; i--){
		if(mp[i]&&possible(v[num].first,v[num].second,i,temp)){
			// 1로 채워주기 
			int temp2[10][10];
			memcpy(temp2,temp,sizeof(temp2));
			for(int j=v[num].first; j<v[num].first+i; j++){
				for(int k=v[num].second; k<v[num].second+i; k++){
					temp[j][k]=1;
				}
			} 
			mp[i]--;
			go(num+1, cnt+1,temp);
			mp[i]++;
			memcpy(temp,temp2,sizeof(temp2));
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
//	cout<<possible(1,1,3);
	    int visited[10][10] = {0};

	go(0,0,visited);
	if(ret==987654321) cout<<-1;
	else
	cout<<ret;
	
	return 0;
} 
