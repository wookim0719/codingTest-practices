#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[21][21];
int visited[21][21];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int ret;

void shows(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j]==-2) cout<<"x"<<" ";
			else
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	return;
}

pair<int,int> counting(int y, int x){
	int sum=1;
	int sum2=0;
	int color= a[y][x];
	if(a[y][x]==0)sum2++;
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x]=1;
	while(q.size()){
		auto f=q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny= f.first+dy[i];
			int nx= f.second+dx[i];
		//	cout<<ny<<" "<<nx<<"\n";
			if(ny<0||nx<0||ny>=n||nx>=n||(visited[ny][nx])||a[ny][nx]==-2||a[ny][nx]==-1||(a[ny][nx]!=color&&a[ny][nx]!=0))
			continue;
			else{
				if(a[ny][nx]==0)sum2++;
				sum++;
				visited[ny][nx]=1;
				q.push({ny,nx});
			}
		}	
	}
	//cout<<sum<<"\n";

	return {sum,sum2};
}
pair<int,int> find_big(){
	memset(visited,0,sizeof(visited));
	int yy=-1; int xx=-1;
	int mmax=2;
	int mmax2=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]&& a[i][j]!=-1 && a[i][j]!=-2&&a[i][j]!=0){
				auto nn= counting(i,j);
				if(nn.first>=mmax){
					if(nn.first==mmax){
						if(nn.second>=mmax2){
							mmax=nn.first;
							mmax2=nn.second;
							yy=i; xx=j;
						}
					}
					else{
						mmax=nn.first;
						mmax2=nn.second;
						yy=i; xx=j;
					}
				}
			for(int i=0;i<n; i++){
				for(int j=0; j<n; j++){
					if(a[i][j]==0)visited[i][j]=0;
				}
			}
			}	
		}
	}
	return {yy,xx};
}

void add_clear(int y, int x){
	memset(visited,0,sizeof(visited));
	int sum=1;
	int color= a[y][x];
	queue<pair<int,int>> q;
	q.push({y,x});
	a[y][x]=-2;
	visited[y][x]=1;
	while(q.size()){
		auto f=q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny= f.first+dy[i];
			int nx= f.second+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]||a[ny][nx]==-2||a[ny][nx]==-1||(a[ny][nx]!=color&&a[ny][nx]!=0))
			continue;
			else{
				sum++;
				visited[ny][nx]=1;
				a[ny][nx]=-2;
				q.push({ny,nx});
			}
		}	
	}
	ret+=sum*sum;
	return;
}

void gravity(){
	queue<int> q;
	int cnt=0;
	for(int i=0; i<n; i++){
		int sidx=0;
		cnt=0;
	//	cout<<q.size()<<"\n";
		for(int j=0; j<n; j++){
			if(a[j][i]!=-1){
				if(a[j][i]!=-2)
				q.push(a[j][i]);
				else{
				//	cout<<j<<" "<<i<<" "<<"ºóÆ´"<<"\n";
					cnt++;
				}
			}
			else{
				int ttt=q.size();
				for(int k=0; k<cnt+ttt; k++){
					if(k<cnt)
					a[sidx+k][i]=-2;
					else{
						a[sidx+k][i]=q.front();
						q.pop();
					}
				}
				cnt=0;
				sidx=j+1;
		//		if(i==2) cout<<"sidx"<<" "<<sidx<<"\n";
			}
		}
		if(q.size()){
		//	cout<<i<<" "<<sidx<<" "<<q.size()<<" "<<cnt<<"\n";
			int tt= q.size();
			for(int k=0; k<cnt+tt; k++ ){
					if(k<cnt)
					a[sidx+k][i]=-2;
					else{
			//			cout<<i<<" "<<stk.top()<<"\n";
		//			cout<<q.size()<<" "<<q.front()<<"³ª¿È"<<"\n";
						a[sidx+k][i]=q.front();
						q.pop();
					}	
			}
		}
	}
	return;
}

void rot(){
	int k=0;
	vector<int> vv;
	while((n/2)!=k){
		vv.clear();
		for(int i=k; i<n-k-1; i++){
			vv.push_back(a[k][i]);
		}
		for(int i=k; i<n-k-1; i++){
			vv.push_back(a[i][n-k-1]);
		}
		for(int i=n-k-1; i>k; i--){
			vv.push_back(a[n-k-1][i]);
		}
		for(int i=n-k-1; i>k; i--){
			vv.push_back(a[i][k]);
		}
		rotate(vv.begin(),vv.begin()+n-k*2-1,vv.end());
		int cnt2=0;
		for(int i=k; i<n-k-1; i++){
			a[k][i]=vv[cnt2];
			cnt2++;
		}
		for(int i=k; i<n-k-1; i++){
			a[i][n-k-1]=vv[cnt2];
			cnt2++;
		}
		for(int i=n-k-1; i>k; i--){
			a[n-k-1][i]=vv[cnt2];
			cnt2++;
		}
		for(int i=n-k-1; i>k; i--){
			a[i][k]=vv[cnt2];
			cnt2++;
		}
		k=k+1;
	}
}


bool auto_play(){
	bool flag= false;
	pair<int,int> yx= find_big();
	//cout<<yx.first<<" "<<yx.second<<"\n";
	if(yx.first==-1){
		return flag;
	}
	else{
		flag= true;
		int y= yx.first;
		int x= yx.second;
	add_clear(y,x);	
//	cout<<"\n";
//	shows();
	gravity();
//	cout<<"\n";
//	shows();
	rot();
	gravity();
//	cout<<"\n";
//	shows();
	}
	return flag;
}


int main(){
	cin>>n>>m;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	while(true){
	//cout<<"ÇÏ±â Àü"<<"\n";
//	shows();
	bool flag= auto_play();
//	cout<<"ÇÑ ÈÄ"<<"\n";
//	shows();
//	cout<<ret<<"\n";
//	cout<<"\n";
	if(!flag) break;
	}
	
	cout<<ret;
	return 0;
}
