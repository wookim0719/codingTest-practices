#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[65][65];
int nn;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int visited[65][65];
vector<int> temp;
int grt;
int ret;

void check(){
	vector<pair<int,int>> v;
	v.clear();
	for(int i=0; i<nn; i++){
		for(int j=0; j<nn;j++){
			int num=0;
			for(int k=0; k<4; k++){
				int ny= i+dy[k];
				int nx= j+dx[k];
				if(ny<0||nx<0||ny>=nn||nx>=nn||a[ny][nx]==0) num++;
			}
			if(num>1) v.push_back({i,j});
		}
	}
	for(auto pp: v){
		if(a[pp.first][pp.second]!=0)
		a[pp.first][pp.second]--;
	}
	return;
}
void bfs(int y,int x){
	queue<pair<int,int>> q;
	visited[y][x]=1;
	q.push({y,x});
	int cnt2=1;
	while(q.size()){
		auto pp = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny= dy[i]+pp.first;
			int nx= dx[i]+pp.second;
			if(ny<0||nx<0||ny>=nn||nx>=nn||a[ny][nx]==0||visited[ny][nx])continue;
			else{
				visited[ny][nx]=1;
				cnt2++;
				q.push({ny,nx});
			}
		}
	}
	grt = max(grt,cnt2);
	return;	
}
void go(int y, int x, int interval){
	int cnt2= interval;
	int cnt=0;
	int goal= cnt2/2;
	int sy=y; 
	int sx=x;
	while(true){
		temp.clear();
		if(cnt==goal) break;
	//	cout<<cnt<<"\n";
		for(int i=cnt+x; i<x+cnt2-cnt; i++){
			temp.push_back(a[cnt+y][i]);
	//		cout<<cnt+y<<" "<<i<<"\n";
		}
	//	cout<<"\n";
		for(int i=cnt+y+1; i<y+cnt2-cnt; i++){
			temp.push_back(a[i][x+cnt2-cnt-1]);
	//		cout<<i<<" "<<x+cnt2-cnt-1<<"\n";
		}
	//		cout<<"\n";

		for(int i=x+cnt2-2-cnt; i>=x+cnt; i--){
			temp.push_back(a[y+cnt2-cnt-1][i]);
	//		cout<<y+cnt2-cnt-1<<" "<<i<<"\n";
		}
	//	cout<<"\n";
		for(int i=y+cnt2-2-cnt; i>y+cnt; i--){
			temp.push_back(a[i][x+cnt]);
	//		cout<<i<<" "<<x+cnt<<"\n";
		}
		int sss= temp.size()/4;
		rotate(temp.begin(),temp.end()-sss,temp.end());
		queue<int> q;
		
		for(int i: temp)
		q.push(i);
		
		for(int i=cnt+x; i<x+cnt2-cnt; i++){
			a[cnt+y][i]=q.front();
			q.pop();
		}
		for(int i=cnt+y+1; i<y+cnt2-cnt; i++){
			a[i][x+cnt2-cnt-1]=q.front();
			q.pop();
		}
		for(int i=x+cnt2-2-cnt; i>=x+cnt; i--){
			a[y+cnt2-cnt-1][i]=q.front();	
			q.pop();
		}
		for(int i=y+cnt2-2-cnt; i>y+cnt; i--){
			a[i][x+cnt]=q.front();
			q.pop();
		}
		
		cnt++;
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	nn= pow(2,n);	
	for(int i=0; i<nn; i++)	{
		for(int j=0; j<nn; j++){
			cin>>a[i][j];
		}
	}
	while(true){
		if(q==0) break;
		int l;
		cin>>l;
		int d= pow(2,l);
		for(int i=0; i<nn; i=i+d){
			for(int j=0; j<nn; j=j+d){
				//cout<<i<<" "<<j<<"\n";
				go(i,j,d);
			}
		}
		q--;
		
		check();
	}
		for(int i=0; i<nn; i++){
		for(int j=0; j<nn; j++){
			ret+=a[i][j];
		}
	}
	
	for(int i=0; i<nn; i++){
		for(int j=0; j<nn; j++){
			if(!visited[i][j]&&a[i][j])
			bfs(i,j);
		}
	}
	
	
	cout<<ret<<"\n";
	cout<<grt;
		
	return 0;
}
