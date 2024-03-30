#include<bits/stdc++.h>
using namespace std;
int n,ret;
int a[17][17];
pair<int,int> pipea;
pair<int,int> pipeb;
vector<pair<int,int>> wall;

void pipe(pair<int,int> a, pair<int,int> b){
	int difx= b.second-a.second;
	int dify= b.first- a.first;
	if(a.first>=n||a.second>=n||b.first>=n||b.second>=n){
	//	cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";
		return ;	
	}
	for(auto i : wall){
		if(i.first==a.first&& i.second==a.second)
		return;
		if(i.first==b.first&& i.second==b.second)
		return;
		if(difx&&dify){
			if(b.first-1 == i.first&&b.second == i.second)
			return;
			if(b.first == i.first && b.second-1== i.second)
			return;
		}
		
	}
	//	cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";
	if(b.first == n-1 && b.second==n-1){
		ret++;
		return;
	}
	//cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";
	//형태가 대각선인 경우  
	if(difx&&dify){
	//	cout<<"대각선"<<"\n"; 
		 	pipe({a.first+1,a.second+1}, {b.first,b.second+1});
		 	pipe({a.first+1,a.second+1},{b.first+1,b.second});
		 	pipe({a.first+1,a.second+1},{b.first+1,b.second+1});
		 }
	
	if(difx&&!dify){
	//			cout<<"가로"<<"\n"; 
			pipe({a.first,a.second+1}, {b.first,b.second+1});
		 	pipe({a.first,a.second+1},{b.first+1,b.second+1});
	}
	if(!difx&&dify){
	//				cout<<"세로"<<"\n";  
			pipe({a.first+1,a.second}, {b.first+1,b.second});
		 	pipe({a.first+1,a.second},{b.first+1,b.second+1});
	}

}



int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j]==1) {
			wall.push_back({i,j});
		}
		}
		
	}
	pipea= {0,0};
	pipeb= {0,1};
	
	pipe(pipea,pipeb);
	
	cout<<ret;
	
	return 0;	
}
