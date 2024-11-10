#include<bits/stdc++.h>
using namespace std;
int n,m;
const int INF=98765432;
int dp[101][101];
int ret=INF;
int res=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		fill(dp[i],dp[i]+101,INF);
	}
	
	for(int i=0; i<n; i++){
		dp[i][i]=0;
	}
	
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		t1--;t2--;
		dp[t1][t2]=1;
		dp[t2][t1]=1;
	}
	
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				dp[i][j]= min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		int sum=0;
		for(int j=0; j<n; j++){
			sum+=dp[i][j];
		}
		if(ret>sum){
			ret= sum;
			res= i+1;
		}
	}
	
	//cout<<ret<<"\n";
	cout<<res;
			
	return 0;
}
