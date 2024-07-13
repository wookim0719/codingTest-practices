#include<bits/stdc++.h>
using namespace std;
int n,m,l,k;
vector<pair<int,int>>v;
int ret;

//오른쪽 아래  
int check1(int y, int x){
	int cnt=0;
	for(int j=0; j<k; j++){
				int xx=v[j].second;
				int yy=v[j].first;
				if(xx>=x&&xx<=x+l){
					if(yy>=y&&yy<=y+l){
						cnt++;
					}
				}
			
		}
	return cnt;
} 
// 오른쪽  위  
int check2( int y, int x){
	int cnt=0;
	for(int j=0; j<k; j++){
				int xx=v[j].second;
				int yy=v[j].first;
				if(xx>=x&&xx<=x+l){
					if(yy<=y&&yy>=y-l){
						cnt++;
					}
				}
			
		}
	return cnt;
}
// 왼쪽 위  
int check3(int y, int x){
	int cnt=0;
	for(int j=0; j<k; j++){
				int xx=v[j].second;
				int yy=v[j].first;
				if(xx<=x&&xx>=x-l){
					if(yy<=y&&yy>=y-l){
						cnt++;
					}
				}
			
		}
	return cnt;
}
// 왼쪽 아래   
int check4( int y, int x){
	int cnt=0;
	for(int j=0; j<k; j++){
				int xx=v[j].second;
				int yy=v[j].first;
				if(xx<=x&&xx>=x-l){
					if(yy>=y&&yy<=y-l){
						cnt++;
					}
				}
		}
	return cnt;
}


int main(){
	cin>>m>>n>>l>>k;
	
	for(int i=0; i<k; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		v.push_back({temp2,temp1});
	}
	
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
		int y= v[i].first;
		int x= v[j].second;
		ret= max(ret,check1(y,x));	
		}	
	}
	
	cout<<k-ret;
	return 0;
}
