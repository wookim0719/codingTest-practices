#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[1000001];
ll bigg=0;
ll ret,sum;

bool check(int len){
	ll total =0;
	for(int i=0; i<n; i++){
		if(len!=0)
		total += a[i]/len;
	}
	if(total>= m) return true;
	else return false;
}

int main(){
	cin>>n>>m;
	
	for(ll i=0; i<n; i++){
		cin>>a[i];
		bigg= max(bigg,a[i]);
		sum+=a[i];
	}
	ll lo=1;
	ll mid=0;
	ll hi=bigg;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(check(mid)){
			lo=mid+1;
			ret= max(mid,ret);
		}
		else{
			hi=mid-1;
		}
	}
	
	sum= sum-(ret*m);
	cout<<sum;
	return 0;
}
