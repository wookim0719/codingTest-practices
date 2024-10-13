#include<bits/stdc++.h>
using namespace std;
int n,m,h;
int a[101][101][101];
int visited[101][101][101];
int dy[6] = {-1,0,1,0,0,0};
int dx[6] = {0,-1,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int cnt;
int cnt2;
int ret;
struct t{
	int v1,v2,v3,num;
};


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<t> q;
	cin>>m>>n>>h;
	for(int k=0; k<h; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>a[i][j][k];
				if(a[i][j][k]==0){
					cnt++;
				}
				if(a[i][j][k]==1){
					cnt2++;
					t temp;
					temp.num=0;
					temp.v1=i;
					temp.v2=j;
					temp.v3=k;
					q.push(temp);
					visited[i][j][k]=1;
				}
			}
		}
	}
	while(q.size()){
		auto f= q.front();
		q.pop();
		ret=max(ret,f.num);
		int hh= f.v3;
		int yy= f.v1;
		int xx= f.v2;
		for(int i=0; i<6; i++){
			int ny = yy+dy[i];
			int nx = xx+dx[i];
			int nz = hh+dz[i];
			if(nz<0||nz>=h||ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx][nz]||a[ny][nx][nz]==-1||a[ny][nx][nz]==1) continue;
			else{
				cnt--;
				cnt2++;
				visited[ny][nx][nz]=1;
				a[ny][nx][nz]=1;
				t temp2;
				temp2.v1=ny;
				temp2.v2=nx;
				temp2.v3=nz;
				temp2.num= f.num+1;
				q.push(temp2);
			}
		}
	}
	if(cnt==0)
	cout<<ret;
	else cout<<-1;
	
	return 0;
}
