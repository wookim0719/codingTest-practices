#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> T;
int a[21][21];
int n,y,x;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[21][21];
int siz=2;
vector<T> v;
int ret;
int gage;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j]==9){
				x= j;
				y= i;
				a[i][j]=0;
			}
		}
	}

	while(true){
	memset(visited,0,sizeof(visited));
	v.clear();
	queue<T> q;
	q.push({0,{y,x}});
	visited[y][x]=1;
	while(q.size()){
		T f= q.front();
		q.pop();
		pair<int,int> xy= f.second;
		for(int i=0; i<4; i++){
			int ny= xy.first+dy[i];
			int nx= xy.second+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]||siz<a[ny][nx])continue;
			visited[ny][nx]=1;
			if(a[ny][nx]<siz&&a[ny][nx]>0)
			v.push_back({f.first+1,{ny,nx}});
			q.push({f.first+1,{ny,nx}});
		}	
	}
	if(v.size()==0) break;
	sort(v.begin(),v.end());
	T temp= v[0];
	ret += temp.first;
	gage++;
	if(gage==siz){
		siz++;
		gage=0;
	}
	y= temp.second.first;
	x= temp.second.second;
	a[y][x]=0;
//	cout<<y+1<<" "<<x+1<<" "<<size<<"\n";
	}	
	cout<<ret;		
	return 0;
}
