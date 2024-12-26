#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a,b,c,d;
vector<ll> sum;
map<ll,int> mp;
vector<ll> sum2;
ll ret;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0; i<n; i++){
		ll t1,t2,t3,t4;
		cin>>t1>>t2>>t3>>t4;
		a.push_back(t1);
		b.push_back(t2);
		c.push_back(t3);
		d.push_back(t4);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sum.push_back(a[i]+b[j]);
			sum2.push_back(c[i]+d[j]);
		//	mp[c[i]+d[j]]++;
		}
	}
	sort(sum.begin(),sum.end());
	sort(sum2.begin(),sum2.end());
	
	for(int i=0; i<sum.size(); i++){
		int B_pre = lower_bound(sum2.begin(), sum2.end(), -sum[i]) - sum2.begin();
		int B_end = upper_bound(sum2.begin(), sum2.end(), -sum[i]) - sum2.begin();
		ret += (B_end - B_pre);
	}
	
	cout<<ret;
	
	return 0;
}
