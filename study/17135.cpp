#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int a[17][16];
int dy[3]={0,-1,0};
int dx[3]={-1,0,1};
struct enemy{
	int y,x,cnt;
};
int ret=0;

pair<int,int> find(int y,int x){
	int visited[17][16];
	memset(visited,0,sizeof(visited));
	enemy temp;
	temp.y=y; temp.x=x; temp.cnt=0;
	queue<enemy> q;
	q.push(temp);
	visited[y][x]=1;
		while(q.size()){
			enemy c= q.front();	
			q.pop();
			for(int i=0; i<3; i++){
				int ny= c.y+dy[i];
				int nx= c.x+dx[i];
				if(ny>=0&&nx>=0&&ny<n&&!visited[ny][nx]){
				visited[ny][nx]=1;
				if(a[ny][nx]==1) { 
				return {ny,nx};
				break;
			}
				else{
				enemy temp2;
				temp2.y=ny; temp2.x=nx; temp2.cnt=c.cnt+1;
				if(temp2.cnt<d)
					q.push(temp2);
				}
				}
			}
		}
		return {-1,-1};
}

int go(int f, int s, int t){
	int board[17][16];
	memcpy(board,a,sizeof(a));
	int res=0;
	while(true){
		bool flag=true;
		auto r1= find(n,f);
		auto r2= find(n,s);
		auto r3= find(n,t);
		pair<int,int> w={-1,-1};
		if(r1!=w&&a[r1.first][r1.second]!=0){
			a[r1.first][r1.second] =0;
			res++;
	}
		if(r2!=w&&a[r2.first][r2.second]!=0){
			a[r2.first][r2.second] =0;
			res++;
	}
		if(r3!=w&&a[r3.first][r3.second]!=0){
			a[r3.first][r3.second] =0;
			res++;
	}
//		for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	
	for(int i=n-1; i>=1; i--){
		for(int j=m-1; j>=0; j--){
			a[i][j] = a[i-1][j];
			if(a[i][j]==1) flag= false;
		}
	}
	for(int i=0; i<m; i++){
		a[0][i]=0;
	}

		if(flag) break;	
	}
	
	memcpy(a,board,sizeof(board));
	return res;	
}


int main(){
	cin>>n>>m>>d;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=i+1; j<m; j++){
			for(int k=j+1; k<m; k++){
			ret= max(ret,go(i,j,k));
			}
		}
	}
	cout<<ret;	
	return 0;
}
