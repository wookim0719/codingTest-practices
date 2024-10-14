#include<bits/stdc++.h>
using namespace std;
char a[31][31][31];
int visited[31][31][31];
int t;
int dx[6]={-1,0,1,0,0,0};
int dy[6]={0,-1,0,1,0,0};
int dz[6]={0,0,0,0,-1,1};
int ret;
const int INF =987654321;
struct room{
	int y,x,h,cnt;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true){
		int l,r,c;
		cin>>l>>r>>c;
		ret=INF;
		if(l==0&&r==0&&c==0) break;
		else{
			memset(visited,0,sizeof(visited));
			int y,x,h;
			int desy,desx,desz;
			for(int i=0; i<l; i++){
				for(int j=0; j<r; j++){
					for(int k=0; k<c; k++){
						cin>>a[j][k][i];
						if(a[j][k][i]=='S') {
							y=j; x=k; h=i;
						}
						if(a[j][k][i]=='E'){
							desy=j; desx=k; desz=i;
						}
					}
				}
			}
			queue<room> q;
			room temp;
			temp.cnt=0;
			temp.y= y; temp.x=x; temp.h=h;
			q.push(temp);
			while(q.size()){
				auto f=q.front();
				q.pop();
			if(f.y==desy&&f.x==desx&&f.h==desz){
				ret=f.cnt;
				break;
			}
			for(int i=0; i<6;i++){
				int ny= f.y+dy[i];
				int nx= f.x+dx[i];
				int nz= f.h+dz[i];
				if(ny<0||nx<0||nz<0||ny>=r||nx>=c||nz>=l||visited[ny][nx][nz]||a[ny][nx][nz]=='#') continue;
				visited[ny][nx][nz]=1;
				room temp2;
				temp2.y=ny; temp2.x=nx; temp2.h=nz; temp2.cnt=f.cnt+1;
				q.push(temp2);
			}
			}		
		}
		if(ret!=INF)
			cout<<"Escaped in "<<ret<<" "<<"minute(s)."<<"\n";
		else cout<<"Trapped!"<<"\n";
		}
	
	
	return 0;
}
