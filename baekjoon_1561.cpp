#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max_n 60000000004
ll n,m;
ll a[10001];
ll ret = 10001;
ll num;

bool check(ll mid){
	ll cnt=m;
	for(ll i=0; i<m;i++){
		cnt = cnt + (mid/a[i]);
	}
	return cnt>=n;
}

int main(){
	cin>>n>>m;
	for(ll i=0; i<m; i++){
		cin>>a[i];
	}
	
	ll lo = 1; 
	ll hi = max_n;
	
	if(n-m<=0) {
	cout<<n; return 0;}
	
	else{
	while(lo<=hi){
		ll mid= (hi+lo)/2;
		if(check(mid)){
			ret = mid;
			hi = mid-1;
		}
		else 
			lo =mid +1;
	}
	num = m;
	for(ll i=0; i<m; i++){
		num += (ret-1)/a[i];
	}
	
	for(ll i=0; i<m; i++){
		if(ret % a[i] ==0) num++;
		if(num == n){
			cout<<i+1<<"\n";
			return 0;
		}
	}
}

	return 0;
}
