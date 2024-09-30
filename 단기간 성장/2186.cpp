#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char a[101][101];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int dp[101][101][80];
string answer;
int res;

int go(int y, int x,int cnt){
//	cout<<y<<" "<<x<<"\n";
	if(cnt==answer.size()){
		return 1;
	}
	int &ret= dp[y][x][cnt];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=0; i<4; i++){
		for(int t=1; t<=k; t++){
			int ny= y+t*dy[i];
			int nx= x+t*dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||answer[cnt]!=a[ny][nx]) continue;
			else{
			//	cout<<ny<<" "<<nx<<"\n";
				ret += go(ny,nx,cnt+1);
			}
		}
	}
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(int j=0; j<m; j++){
			a[i][j]=s[j];
		}
	}
	cin>>answer;
	memset(dp,-1,sizeof(dp));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]==answer[0]){
//				cout<<go(i,j,1)<<"\n";
//				cout<<"\n";
				res+=go(i,j,1);
			}
		}
	}
	cout<<res;
	
	return 0;
}
