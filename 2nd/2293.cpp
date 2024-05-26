#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,k;
int a[101];
int dp[10002];
int value;

int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i]>10001) continue;
		dp[a[i]]++;
		for(int j=a[i]; j<=k; j++){
			dp[j] +=dp[j-a[i]];
		}	
	}
		
	cout<<dp[k];
	
	return 0;
}
