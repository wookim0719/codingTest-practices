#include<bits/stdc++.h>
using namespace std;
int n;
int dp[10001];
int goal;
int ret;

void go(){
	for(int i=1; i<=3; i++){
		for(int j=1; j<=10000; j++){
			if(j-i>=0) dp[j] += dp[j-i];
		}
	}
}


int main(){
	cin>>n;
	dp[0]=1;
	go();
	while(n--){
		cin>>goal;
		cout<<dp[goal]<<"\n";
	}
	return 0;
}
