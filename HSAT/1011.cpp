#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

ll go(ll value){
	ll start=0;
	ll end = 1e10;
	ll ret=1e10;
	while(start<=end){
		ll mid = (start+end)/2;
		ll v= mid*(mid+1)/2+(mid-1)*(mid)/2;
		if(v>=value){
			ret= min(ret,mid);
			end = mid-1;
		}
		else{
			start= mid+1;
		}
	}
	ll value2= ret*(ret+1)/2+(ret-1)*ret/2;
	if(value2==value)return ret+ret-1;
	else{
	if((value2-ret)<value) return ret+ret-1;
	else if((value2-ret-ret-1)<value)return ret+ret-2;	
	else return ret+ret-3;
	}
}

int main(){
	cin>>n;
	while(n--){
		ll t1,t2;
		cin>>t1>>t2;
		ll gap = t2-t1;
		cout<<go(gap)<<"\n";
	}
	
	return 0;
}
