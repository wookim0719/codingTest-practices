#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll vv = 1000000007;
int m;
ll a,b;
ll res;

ll go(ll bb){
	ll result = 1;
	ll base = bb;
	ll k = vv-2;
	while(k>0){
		if(k%2){
			result = (result*base)%vv;	
		}
		base = (base*base)%vv;
		k=k/2;
	}
	return (result)%vv;
} 


int main(){
	cin>>m;
	
	while(m--){
		cin>>a>>b;
		ll value = b*go(a)%vv;
		res = res+value%vv;
	}
	cout<<res%vv;
	return 0;
}
