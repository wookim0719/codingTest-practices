#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int dp2[1001];
int n;
int ret;
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(v[i]>v[j]){
				dp[i] = max(dp[j]+1,dp[i]);
			}
		}
	}
	
	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(v[i]>v[j]){
				dp2[i] = max(dp2[j]+1,dp2[i]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		ret= max(ret,dp[i]+dp2[i]+1);
	}
	cout<<ret;
	return 0;
}
