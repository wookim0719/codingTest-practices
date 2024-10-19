#include<bits/stdc++.h>
using namespace std;
int n;
int ret;
int value=1;
int dp[1001];

int go2(int nnn){
	int v2=1;
	for(int i=1; i<=nnn; i++){
		v2*=i;
	}
	return v2;
}
int cal(int n1,int n2){
	int value2=go2(n-n1-n2);
	value2 /= go2(n1);
	value2 /= go2(n2);
	value2 /= go2(n-2*n1-2*n2);
	return value2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;

	dp[1]=1;
	dp[2]=3;

	for(int i=3; i<=1000; i++){
			dp[i] =(dp[i-1]+2*dp[i-2])%10007;
		}
	
	
	cout<<dp[n];
	
	return 0;
}
