#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2001];
int dp[2001][2001];

int check(int s, int e){
	if(s>=e)return 1;
	int& ret= dp[s][e];
	if(ret!=-1) return ret; 
	ret= (a[s]==a[e])&&check(s+1,e-1);
	
	return ret;
}



int main(){
	    ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cin>>m;
	for(int i=0; i<m; i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
	int res=check(temp1-1,temp2-1);
	cout<<res<<"\n";
	}
	return 0;
}

