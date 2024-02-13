#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int m,n,k;
const int max_mn=101;
int a[max_mn][max_mn];
int visited[max_mn][max_mn];
vector<int> output;

int dfs(int y, int x){
	visited[y][x]=1;
	int volume=1;
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=m||nx>=n) continue;
		if(!visited[ny][nx] && a[ny][nx]!=1) {
		 volume+= dfs(ny,nx);		
		}
	}
	return volume;
}


int main(){
	int cnt =0;
	cin>>m>>n>>k;
	for(int i=0; i<k; i++){
		int	tempx1,tempx2,tempy1,tempy2;
		cin>>tempx1>>tempy1>>tempx2>>tempy2;
		for(int j=tempx1; j<tempx2; j++){
			for(int t=tempy1; t<tempy2; t++){
				a[t][j] =1;
			}
		}
	}

	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
		 if(a[i][j] != 1 & visited[i][j] == 0){
				output.push_back(dfs(i,j));
				cnt++;
			}
		}
	}
	
	cout<<cnt<<"\n";
	sort(output.begin(),output.end());
	for(int i=0; i<cnt; i++)
	cout<<output[i]<<" ";
	
	return 0;
	
}
