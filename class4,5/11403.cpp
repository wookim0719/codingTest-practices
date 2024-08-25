#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
int dp[101][101];
const int INF=987654321;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		fill(dp[i],dp[i]+101, INF);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				dp[i][j]=1;
				a[j][i]=1;		
			}
		}
	}
	
	
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				dp[i][j]= min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(dp[i][j]==INF) cout<<0<<" ";
			else cout<<1<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
