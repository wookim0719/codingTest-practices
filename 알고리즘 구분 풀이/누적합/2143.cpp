#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int> mp;
int n,m;
ll goal;
vector<int> a;
vector<int> b;
ll ret;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>goal>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	cin>>m;
	for(int i=0; i<m; i++){
		int temp;
		cin>>temp;
		b.push_back(temp);
	}
	
	for(int i=0; i<n; i++){
		ll sum= a[i];
		mp[sum]++;
		for(int j=i+1; j<n; j++){
			sum+=a[j];
		//	cout<<sum<<"\n";
			mp[sum]++;
		}
	}
	for(int i=0; i<m; i++){
		ll sum= b[i];
		if(mp[goal-sum]){
			ret+=mp[goal-sum];
		}
		for(int j=i+1; j<m; j++){
			sum+=b[j];
		//	cout<<sum<<"\n";
		if(mp[goal-sum]){
			ret+=mp[goal-sum];
		}
		}
	}
	
	cout<<ret;
	return 0;
}
