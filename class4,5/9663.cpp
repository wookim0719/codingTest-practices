#include<bits/stdc++.h>
using namespace std;
int n;
int ret;
int a[16];
int d1[32];
int d2[32];
//int dy[8]={-1,0,1,0,1,-1,1,-1};
//int dx[8]={0,1,0,-1,1,1,-1,-1};
//int visited[16][16][8];
//int visited2[16][16];
//vector<pair<int,int>> v;

//bool possible(int y, int x){
//	memset(visited,0,sizeof(visited));
//	int flag=true;
//	for(int i=0; i<v.size(); i++){
//		pair<int,int> f = v[i];
//	for(int d=0; d<8; d++){
//		int ny= 1f.first;
//		int nx= f.second;
//		while(true){
//		ny = ny+dy[d];
//		nx = nx+dx[d];
//		if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx][d]) break;
//		visited[ny][nx][d]=1;
//		if(ny==y&&nx==x){
//		return false;
//		break;
//		} 
//	}
//		}
//					
//	}
//	return flag;	
//}

void dfs(int y,int cnt){
	if(cnt==n){
		ret++;
		return;
	}
		for(int j=0; j<n; j++){
			if(!a[j]&&!d1[y+j]&&!d2[y-j+n]){
				a[j]=1;
				d1[y+j]=1;
				d2[y-j+n]=1;
				dfs(y+1,cnt+1);
				a[j]=0;
				d1[y+j]=0;
				d2[y-j+n]=0;
			}
		}
	
	return;
}


int main(){
	 ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	dfs(0,0);
	cout<<ret;
	
	return 0;
}
