#include<bits/stdc++.h>
using namespace std;
int n;
int dp[3][1001][3];
int a[1000][3];
const int INF = 987654321;
int ret= INF;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<n; j++){
			fill(dp[i][j],dp[i][j]+3,INF);
		}
	}
	
	dp[0][0][0]= a[0][0];
	dp[1][0][1]= a[0][1];
	dp[2][0][2]= a[0][2];
	
	for(int k=0; k<3; k++){
	for(int i=1; i<n; i++){
		for(int j=0; j<3; j++){
			if(i!=n-1||k!=j)
			dp[k][i][j] = min(dp[k][i][j], dp[k][i-1][(j+1)%3]+a[i][j]);
			if(i!=n-1||k!=j)
			dp[k][i][j] = min(dp[k][i][j], dp[k][i-1][(j+2)%3]+a[i][j]);	
		}
	}	
	}

	for(int j=0; j<3; j++){
		for(int i=0; i<3; i++){
		ret= min(ret,dp[j][n-1][i]);
	}		
	}

	
	cout<<ret;
	
	return 0;
}
