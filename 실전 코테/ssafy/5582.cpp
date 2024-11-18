#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[4001][4001];
int ret=0;
int n=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	n = min(a.size(),b.size());
	
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if(a[i]==b[j]) {
				if(i>0&&j>0){
					dp[i][j] = dp[i-1][j-1]+1;
					ret= max(dp[i][j],ret);
				}
				else
					dp[i][j]=1;
			}
		}
	}	
	
	cout<<ret;
	return 0;
}
