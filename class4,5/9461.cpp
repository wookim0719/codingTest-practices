#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[101];
int main(){
	cin>>n;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	dp[6]=3;
	
	for(int i=7; i<=100; i++){
		dp[i] = dp[i-5]+dp[i-1];
	}
	while(n--){
		int temp;
		cin>>temp;
		cout<<dp[temp]<<"\n";
	}
	
	return 0;
}
