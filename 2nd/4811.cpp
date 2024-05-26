#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[31][31];

ll divide(int w, int h){
	if(w==0&&h==0) return 1;
	ll &ret= dp[w][h];
	if(dp[w][h]) return ret;
	ret=0;
	if(w>0)
	ret += divide(w-1,h+1);
	if(h>0)
	ret += divide(w,h-1);
	return ret;
}

int main(){
	while(true){
		cin>>n;
		if(n==0) break;
		else
		cout<<divide(n,0)<<"\n";
	}
	
	return 0;
}
