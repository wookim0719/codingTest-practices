#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[1001][1001];
string ret;
vector<char> res;
int main(){	
	cin>>s1>>s2;

	for(int i=1; i<=s1.size(); i++){
		for(int j=1; j<=s2.size(); j++){
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else{
				dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
 		}
	}
	cout<<dp[s1.size()][s2.size()]<<"\n";
	int i=s1.size();
	int j=s2.size();
	
	while(true){
		if(i<0||j<0) break;
		if(dp[i-1][j]==dp[i][j]){
			i=i-1;
		}
		else if(dp[i][j-1]==dp[i][j]){
			j=j-1;
		}
		else{
			res.push_back(s1[i-1]);
			i=i-1;
			j=j-1;
		}
	}
	
	for(int i=dp[s1.size()][s2.size()]-1; i>=0; i--){
		cout<<res[i];
	}
	
	return 0;
}
