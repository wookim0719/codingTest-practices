#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,k;
int a[101];
int dp[100001];
int value;

int go(int temp){
	if(temp==k){
		return 0;	
	}
	int& ret= dp[temp];
	if(dp[temp]) return dp[temp];
	ret = INF;
	for(int i=0; i<n; i++){
		if(a[i]+temp<=k)
		ret= min(ret, go(temp+a[i])+1);
	}
	
	return ret;
}


int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	int value= go(0);
	
	if(value==INF) cout<<-1;
	
	cout<<value;
	return 0;
}
