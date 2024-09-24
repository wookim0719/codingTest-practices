#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int dp[101];
vector<int> lad[101];
vector<int> snake[101];
map<int,int> impo;
const int INF =98765431;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int t1,t2;
		cin>>t1>>t2;
		lad[t2].push_back(t1);
		impo[t1]=1;
	}
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		snake[t2].push_back(t1);
		impo[t1]=1;
	}
	for(int i=1; i<=100; i++){
		a[i]=i;
	}
	fill(dp,dp+101,INF);
	dp[1]=0;
	
	for(int i=2; i<=100; i++){
		for(int j=1; j<=6; j++){
			if(lad[i].size()){
				for(int k=0; k<lad[i].size(); k++){
					dp[i]= min(dp[i],dp[lad[i][k]]);	
				}
			}
			if(snake[i].size()){
				for(int k=0; k<snake[i].size(); k++){
					dp[i]= min(dp[i],dp[snake[i][k]]);	
				}
			}
			if(i-j>=1&&!impo[i-j]){
				dp[i] = min(dp[i],dp[i-j]+1);
			}
		}
	}
		for(int i=2; i<=100; i++){
		for(int j=1; j<=6; j++){
			if(lad[i].size()){
				for(int k=0; k<lad[i].size(); k++){
					dp[i]= min(dp[i],dp[lad[i][k]]);	
				}
			}
			if(snake[i].size()){
				for(int k=0; k<snake[i].size(); k++){
					dp[i]= min(dp[i],dp[snake[i][k]]);	
				}
			}
			if(i-j>=1&&!impo[i-j]){
				dp[i] = min(dp[i],dp[i-j]+1);
			}
		}
	}
//	cout<<dp[80]<<" ";
//	cout<<dp[84]<<" ";
//	cout<<dp[57]<<" "<<dp[56]<<" ";
//	cout<<dp[98]<<" ";
	cout<<dp[100];
	
	return 0;
}
