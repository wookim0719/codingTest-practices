#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dp[1001][501];
int visited[1001];
ll ret;

int go(int num, int remain,int ff){
	if(remain==0) return 1;
	ll& ret= dp[ff][num][remain];
	if(ret) return ret;
	for(int i=num+2; i<=n; i++){
		if((i+1)%n==ff) continue;
		if(visited[i]) continue;
		ret+= go(i,remain-1,ff)%1000000003;
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);W
	cout.tie(NULL);
	cin>>n>>m;
	if(n/2<m)
		 cout<<0;
	else{
		for(int i=1; i<n-m; i++){
			visited[i]=1;
			ret+=go(i,m-1,i)%1000000003;
		}
		cout<<ret;
	}	
	return 0;
}
