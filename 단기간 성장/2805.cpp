#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<ll> v;
ll max_v;
ll ret=0;

ll check(ll mid){
	ll sum=0;
	for(int i=0; i<v.size(); i++){
		if(v[i]>mid){
			sum += v[i]-mid;
		}
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
		if(max_v<temp){
			max_v = temp;
		}
	}

	sort(v.begin(),v.end());
	
	ll s = 0;
	ll e = max_v;
//	cout<<s<<" "<<e<<"\n";
	while(s<=e){
		ll mid = (s+e)/2;
		ll sum = check(mid);
	//	cout<<mid<<" "<<sum<<"\n";
		if(sum>=m){
			ret = max(ret,mid);
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	
	cout<<ret;
	return 0;
}
