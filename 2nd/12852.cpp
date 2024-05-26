#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n;
int dp[1000001];

int check(int a){
	if(a==1){
		return 0;
	}
	int &ret =dp[a];
	if(ret!=INF) return ret;
		
	if(a%3== 0){
		ret = min(ret,check(a/3)+1);
	}
	if(a%2 == 0){
		ret = min(ret,check(a/2)+1);
	}
	if(a>1){
		ret= min(ret,check(a-1)+1);
	}
	return ret;
}
void go(int a){
	cout<<a<<" ";
	if((a%3==0)&&(dp[a]==dp[a/3]+1)){
		go(a/3);
	}
	else if((a%2==0)&&dp[a]==dp[a/2]+1){
		go(a/2);
	}
	else if((a>1)&&dp[a]==dp[a-1]+1){
		go(a-1);
	}
}

int main(){
	fill(dp,dp+1000001,INF);
	cin>>n;
	
	int ret= check(n);
	cout<<ret<<"\n";
	int& o= dp[1];
	o= 0;
	go(n);
	return 0;
}
