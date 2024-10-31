#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll VALUE=1000000003;
int n,m;
//dp는 n개중에서 k개를 고를 수 있는 값을 말한다.  
ll dp[1001][1001];

int main(){
	cin>>n>>m;
	
	for(int i=1; i<=n ; i++){
		dp[i][0]=1;
		dp[i][1]=i;
	}	
	
	for(int i=2; i<=n; i++){
		for(int j=2; j<=m; j++){
			dp[i][j] = (dp[i-1][j]+dp[i-2][j-1])%VALUE;
		}
	} 
	
	cout<<(dp[n-1][m]+dp[n-3][m-1])%VALUE;
	
	return 0;
}
