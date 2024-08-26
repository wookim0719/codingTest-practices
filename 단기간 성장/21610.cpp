#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[51][51];
int c[51][51];
int d,s;
int ret;
vector<pair<int,int>> clouds;
vector<pair<int,int>> temp;
int dy[8]={0,-1,-1,-1,0,1,1,1};
int dx[8]={-1,-1,0,1,1,1,0,-1};

void go(int y, int x){
	int ny= y+dy[d]*s;
	int nx= x+dx[d]*s;
	//cout<<y<<" "<<x<<"\n";
	//cout<<dy[d]<<" "<<dx[d]<<"\n";
	//		cout<<ny<<" "<<nx<<"\n"; 

	if(ny>=n) {
		ny = ny % n;
	}
	if(nx>=n){
		nx= nx % n;
	}
	if(ny<0){
		while(ny<0){
			ny+=n;
		}
	}
	if(nx<0){
		while(nx<0){
			nx+=n;
		}
	}
	temp.push_back({ny,nx});
	c[ny][nx]=1;
	a[ny][nx]++;
	return;
}

void rain(int y, int x){
	int cnt=0;
	for(int i=1; i<8; i+=2){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n) continue;
		if(a[ny][nx]>0)
		cnt++;
	}
	a[y][x]+=cnt;
	return;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	clouds.push_back({n-1,0});
	clouds.push_back({n-1,1});
	clouds.push_back({n-2,0});
	clouds.push_back({n-2,1});

	
	while(m--){
		temp.clear();
		for(int i=0; i<n; i++){
			fill(c[i],c[i]+51, 0);
		}
		cin>>d>>s;
		d--;
		for(int i=0; i<clouds.size(); i++){
			go(clouds[i].first,clouds[i].second);
		}
		clouds.clear();
		for(int i=0; i<temp.size(); i++){
		//	cout<<temp[i].first<<" "<<temp[i].second<<"\n";
			rain(temp[i].first,temp[i].second);
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(a[i][j]>=2&&!c[i][j]){
					a[i][j]-=2;
					clouds.push_back({i,j});
				}
		}	}
		
//		for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout<<a[i][j];
//		}
//		cout<<"\n";
//	}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ret+=a[i][j];
		}
	}
	cout<<ret;
	
	return 0;
}
