#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll ret = 1e9;


int main(){
	cin>>x>>y;
	ll lo=0;
	ll hi=1e9;
	ll original = (y*100)/x;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		ll temp = ((y+mid)*100)/(x+mid);

		if(temp>original){
			ret = mid;
			hi = mid-1;
		}
		else 
			lo = mid+1;
	}
	cout<<ret;
	return 0;
}
