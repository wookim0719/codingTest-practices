#include <bits/stdc++.h>
using namespace std;
#define first f
#define second s  
typedef long long ll;
ll n,m;
ll a[300004], ret = 1e18;

bool check(ll mid){
	ll num = 0;
	for(int i=0; i<m; i++){
		// 핌요한 사람수의 최소를 구하려면 가장 큰 값으로 나눠줘야한다.
		num += a[i]/mid;
		// 나머지가 있으면 1을 더해줘서 몇개의 사람이 필요한지 구한다.
		if(a[i]%mid)num++;
	}
	return n>=num;
}

int main(){
	cin>>n>>m;
	ll lo =1, hi=0, mid;
	for(int i=0; i<m; i++){
		cin>>a[i], hi = max(hi,a[i]);
	}
	while(lo<= hi){
		mid = (lo+hi) /2;
		if(check(mid)){
			ret = min(ret,mid);
			hi = mid-1;
		}
		else 
			lo = mid+1;
	}
	
	cout<<ret;
	
	return 0;
}
