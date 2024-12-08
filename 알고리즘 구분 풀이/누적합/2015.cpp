#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
map<ll,int> mp;
ll ret;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	mp[0]=1;
	ll sum=0;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		sum+=temp;
		if(mp[sum-k]){
		//	cout<<i<<"\n";
			ret+=mp[sum-k];
		}
		mp[sum]++;
	}

	cout<<ret;
	
	return 0;
}
