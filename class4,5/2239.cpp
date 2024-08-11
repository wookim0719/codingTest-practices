#include<bits/stdc++.h>
using namespace std;

int a[10][10];
vector<pair<int,int>> p;
int cnt;
int cnt2;


 bool check(int y, int x, int t){
 	for(int i=0; i<9; i++){
 		if(a[i][x]==t) return false;
	 }
	for(int i=0; i<9; i++){
		if(a[y][i]==t)return false;
	}
	
	int py= y/3;
	int px= x/3;
	for(int i=3*py; i<3*py+3; i++){
		for(int j=3*px; j<3*px+3; j++){
			if(a[i][j]==t) return false;
		}
	}	
	return true;
 }


 void dfs(int num){
 	if(cnt2) return;
 	if(num==cnt){
 		cnt2++;
 		for(int i=0; i<9; i++){
 			for(int j=0; j<9; j++){
 				cout<<a[i][j];
			 }
			 cout<<"\n";
		 }
		 exit(0);
		 return;
	 }
	 	for(int k=1; k<10; k++){
 			if(check(p[num].first,p[num].second,k)){
 					a[p[num].first][p[num].second]=k;
 					dfs(num+1);
 					a[p[num].first][p[num].second]=0;
			 }
		 }
	 return;
 }

int main(){
	for(int i=0; i<9; i++){
		string t;
		cin>>t;
		for(int j=0; j<9; j++){
			a[i][j]= t[j]-'0';
			if(a[i][j]==0) {
				cnt++;
				p.push_back({i,j});
		}
	}
	}
	dfs(0);
	return 0;
}

