#include <bits/stdc++.h>
using namespace std;
const int INF= 987654321;
int t;
int n;
int res=987654321;
int dp[501][501];
int presum[501];
vector<int> v;

int go(int a, int b) {
	if (a == b)
		return dp[a][b];

	int& ret = dp[a][b];
	if (ret != -1)	return ret;

	ret = INF;

	int sum = presum[b+1] - presum[a];
	for (int i = a; i < b; i++) {
		ret = min(ret, go(a, i) + go(i + 1, b) + sum);
	}

	return ret;
}
int main(){
	cin>>t;
	
	while(t--){
		res=INF;
		cin>>n;
		v.clear();
		memset(dp,-1,sizeof(dp));
		for(int i=0; i<n; i++){
			int temp;
			cin>>temp;
			v.push_back(temp);
			dp[i][i]=temp;
		}
		//presum[0]=v[0];
		for(int i=1; i<=n; i++){
			presum[i]=presum[i-1]+v[i-1];
		}
		
		for(int i=0; i<n-1; i++){
			res= min(res,go(0,i)+go(i+1,n-1));
		}
			cout<<res<<"\n";
	}
	
	return 0;
}
