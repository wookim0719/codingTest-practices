#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int n,m,k;
int visited[1001][1001][11];
struct pb{
	int y, x, cnt, brk;
};
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ret;
int main(){
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		for(int j=0; j<m; j++){
			a[i][j]= temp[j]-'0';
		}
	}	
	pb t;
	t.brk=0; t.cnt=1; t.x=0; t.y=0;
	queue<pb> q;
	q.push(t);
	while(q.size()){
		pb f= q.front();
	//	cout<<f.y<<" "<<f.x<<"\n"; 
		q.pop();
		if(f.y==n-1&&f.x==m-1) {
			ret = f.cnt;
			//cout<<f.y<<" "<<f.x<<" "<<f.brk<<"\n";
			break;
		}
		for(int i=0; i<4; i++){
			int ny= dy[i]+f.y;
			int nx= dx[i]+f.x;
			if(ny<0||nx<0||ny>=n||nx>=m) continue;
			if(a[ny][nx]==1){
				if(visited[ny][nx][f.brk+1]||(f.brk+1)>k) continue;
				else{
					visited[ny][nx][f.brk+1]=1;
					pb temp;
					temp.y=ny; temp.x=nx; temp.cnt=f.cnt+1; temp.brk=f.brk+1;
					q.push(temp);
				}
			}
			else{
				if(!visited[ny][nx][f.brk]){
                    visited[ny][nx][f.brk]=1;
					pb temp;
					temp.y=ny; temp.x=nx; temp.cnt=f.cnt+1; temp.brk=f.brk;
					q.push(temp);
				}
			}
		}
	}
	if(ret==0) cout<<-1;
	else
	cout<<ret;
	return 0;
}
