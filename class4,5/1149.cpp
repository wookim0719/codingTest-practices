#include<bits/stdc++.h>
using namespace std;
int n;
int a[1001][3];
int dp[1001][3];
int ret=987654321;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0 ;i<3; i++){
		dp[0][i] = a[0][i];
	}
	
	for(int i=1; i<n; i++){
		for(int j=0; j<3; j++){
			if(j==1)
			dp[i][j] = min(dp[i-1][j-1]+a[i][j],dp[i-1][j+1]+a[i][j]);
			if(j==0)
			dp[i][j] = min(dp[i-1][2]+a[i][j],dp[i-1][j+1]+a[i][j]);
			if(j==2)
			dp[i][j] = min(dp[i-1][0]+a[i][j],dp[i-1][j-1]+a[i][j]);
		}
	}
	
	for(int i=0 ;i<3; i++){
		ret = min(ret, dp[n-1][i]);
	}
	cout<<ret;
	
	
	return 0;
}
