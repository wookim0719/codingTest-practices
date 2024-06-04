#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
string s;
int a[2501][2501];
int dp[2501];
int n;

int go(int here){
	if(here==n) return 0;
	if(dp[here]!=INF)return dp[here];
	int &ret=dp[here];
	for(int i=1; here+i<=n; i++){
		if(a[here][i]) ret=min(ret,go(here+i)+1);
	}
	return ret;
}

int main(){
	cin>>s;
	n=s.size();
	for(int i=0; i<n; i++){
		a[i][1]=1;
	}
	
	for(int i=0; i<n-1; i++){
		if(s[i]==s[i+1]) a[i][2]=1;
	}
	
	for(int _size=3; _size<=s.size(); _size++){
		for(int j=0; j+_size<= n; j++){
			if(s[j] == s[j+_size-1]&& a[j+1][_size-2])
				a[j][_size] =1;
		}
	}
	fill(dp,dp+2501, INF);
	cout<<go(0);
	
	return 0;
}
