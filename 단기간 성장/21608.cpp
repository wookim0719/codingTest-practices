#include<bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int t1,t2,t3,t4,t5;
vector<pair<int,int>> can;
vector<int> like[401];
int dy[4]= {-1,0,1,0};
int dx[4]= {0,1,0,-1};
int ret;

void check(){
	int like=0;
	int blank=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j]) continue;
			int likes=0; int blanks=0;
			for(int k=0; k<4; k++){
				int ny= dy[k]+i;
				int nx= dx[k]+j;
				if(ny<0||nx<0||ny>=n||nx>=n) continue;
				if(a[ny][nx]==0) blanks++;
				else{
					int temp= a[ny][nx];
					if(temp==t2||temp==t3||temp==t4||temp==t5){
						likes++;
					}
				}
			}
//			if(i==0&&j==2)cout<<blanks<<" "<<likes<<"\n";
			if(likes>like){
				like=likes;
				blank=blanks;
				can.clear();
				can.push_back({i,j});
			}
			else if(likes==like){
				if(blanks>blank){
					blank=blanks;
					can.clear();
					can.push_back({i,j});
				}
				else if(blanks==blank){
					can.push_back({i,j});
				}
			}
		}
	}
//	cout<<can.size()<<" "<<like<<" "<<blank<<" "<<can[0].first<<" "<<can[0].second<<"\n";
	return; 
}

int main(){
	cin>>n;
	int cnt= n*n;
	while(cnt--){
	can.clear();
	cin>>t1>>t2>>t3>>t4>>t5;
	like[t1].push_back(t2);
	like[t1].push_back(t3);
	like[t1].push_back(t4);
	like[t1].push_back(t5);
	check();
	sort(can.begin(),can.end());
	a[can[0].first][can[0].second]=t1;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int likes=0;
			for(int k=0; k<4; k++){
				int ny= dy[k]+i;
				int nx= dx[k]+j;
				if(ny<0||nx<0||ny>=n||nx>=n) continue;
					int temp= a[ny][nx];
					int q,w,e,r;
					int value= a[i][j];
					q=like[value][0];
					w=like[value][1];
					e=like[value][2];
					r=like[value][3];
					if(temp==q||temp==w||temp==e||temp==r){
						likes++;
					}
			}
			if(likes>0){
			int tt=1;
			for(int i=1; i<likes; i++){
				tt*=10;
			}
			ret+=tt;	
			}
		}
	}
	cout<<ret;
	return 0;
}
