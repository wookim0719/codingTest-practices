#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001][2];
int dp[100001][2];

int main(){
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
cin>>n;

while(n--){
	int ret=0;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	int num;
	cin>>num;
	for(int i=0; i<2; i++){
		for(int j=0; j<num; j++){
			cin>>a[j][i];
		}
	}
	dp[0][1]= a[0][1];
	dp[0][0] = a[0][0];
	ret= max(dp[0][1],dp[0][0]);
	if(num>1){
	dp[1][1] = dp[0][0] + a[1][1];
	dp[1][0] = dp[0][1] + a[1][0];
	ret= max(dp[1][1],dp[1][0]);	
	for(int i=2 ;i<num; i++){
		for(int j=0; j<2; j++){
			dp[i][j] = max(dp[i-1][1-j]+a[i][j], dp[i-2][1-j]+a[i][j]);
			ret= max(ret,dp[i][j]);
		}
	}
	}

	cout<<ret<<"\n";
}	
	
	return 0;
}
