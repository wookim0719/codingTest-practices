#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,ret;
ll t[130005], ak[130005], hi[130005];


void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}   

bool check(ll mid, ll att){
	ll full=mid;
	ll flag=0;
	for(int i=0; i<n; i++){
			ll p = hi[i];
			ll d = ak[i];
		if(t[i]==1){
			int cnt2= hi[i] / att + (hi[i] % att ? 1:0);
			mid -= (cnt2 -1)*ak[i];
		if(mid<1) flag = 1; 
	}
		else{
			att = att+d;
			if(mid+p<=full) mid = mid+p;
			else mid = full;
		}
	}
	return flag?false:true;
}


int main(){
	fastIO();
	cin>>n>>a;
	for(int i=0; i<n; i++){
	cin>>t[i]>>ak[i]>>hi[i];
	}
	ll lo=1;
	ll hi= 1e18+4 ;
	while(lo<=hi){
	ll mid= (lo+hi)/2;
	if(check(mid,a)){
		ret = mid;
		hi=mid-1;
	}
	else lo =mid+1;
	}	
	cout<<ret;
	return 0;
}
