#include<bits/stdc++.h>
using namespace std;
int n;
const int INF =987654321;
int w[17][17];
int dp[17][1 << 16];

int go(int idx, int visited){
	if(visited == (1<<n)-1){
		return w[idx][0] ? w[idx][0] : INF;
	}
	int &ret= dp[idx][visited];
	if(ret!=-1) return ret;
	ret = INF;
	for(int i=1; i<n; i++){
		if(visited & (1<<i)) continue;
		if(w[idx][i]==0) continue;
		ret = min(ret, go(i,visited | (1<<i))+ w[idx][i]);
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int temp;
			cin>>temp;
			w[i][j] = temp;
		}
	}
	memset(dp,-1,sizeof(dp));
	
	cout<<go(0,1);
	
	return 0;
}
