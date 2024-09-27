#include<bits/stdc++.h>
using namespace std;
int a[25][25];
int visited[25][25];
int n;
int ret;
int cnt;
vector<int> v;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void go(int y,int x){
	//cout<<y<<" "<<x<<"\n";
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];	
		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]||!a[ny][nx]) continue;
		else{
			cnt++;
			visited[ny][nx]=1;
			go(ny,nx);
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		string t;
		cin>>t;
		for(int j=0; j<n; j++){
			a[i][j]= t[j]-'0';
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cnt=0;
			if(a[i][j]==1&&!visited[i][j]){
				visited[i][j]=1;
				cnt++;
				go(i,j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(),v.end());
	
	cout<<v.size()<<"\n";
	for(int i:v) cout<<i<<"\n";
	
	return 0;
}
