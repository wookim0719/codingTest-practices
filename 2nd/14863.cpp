#include<bits/stdc++.h>
using namespace std;
int n,k;
struct how{
	int wt,wv,bt,bv;
};
how v[101];
int dp[101][100001];

int go(int num, int remain){
	if(num==n) {
		return 0;
	}
	int &ret= dp[num][remain];
	if(ret) return dp[num][remain];
	if((remain-v[num].wt>=0)||(remain-v[num].bt>=0)){
	if(remain-v[num].wt>=0){
		ret= max(ret,v[num].wv+go(num+1,remain-v[num].wt));
	}
	if(remain-v[num].bt>=0){
		ret= max(ret,v[num].bv+go(num+1,remain-v[num].bt));
	}
}
else ret+=-987654321;
	return ret;
}

int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int t1,t2,t3,t4;
		cin>>t1>>t2>>t3>>t4;
		how temp;
		temp.wt=t1;
		temp.wv=t2;
		temp.bt=t3;
		temp.bv=t4;
		v[i]=temp;
	}
	
	int res= go(0,k);
	
	cout<<res;
	return 0;
}
