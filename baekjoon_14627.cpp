#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,c;
vector<ll> v;
ll ret;
ll sum;

bool check(ll mid){
	int cnt=0;
	for(int i=0; i<s; i++){
		ll t = v[i]/mid;
		cnt = cnt+t;
	}
	return cnt >= c;
}

int main(){
	cin>>s>>c;
	for(int i=0; i<s; i++){
		ll temp;
		cin>>temp;
		v.push_back(temp);
		sum += v[i];
	}
	sort(v.begin(),v.end());
	ll lo =1;
	ll hi = v[s-1];
	
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			ret = max(ret,mid);
			lo=mid+1;	
		}
		else
			hi = mid-1;	
			
	}
	
	
	cout<<sum - ret*c;
	
	return 0;
}
