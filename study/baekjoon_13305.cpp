#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int city[100001];
ll gas[100001];
ll a[100001];
ll res;

int main(){
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>city[i];
	}
	for(int i=0; i<n; i++){
		cin>>gas[i];
	}
	
	ll min_val=1e16;
	for(int i=0; i<n; i++){
		min_val = min(gas[i],min_val);
		a[i] = min_val;
	//	cout<<a[i]<<"\n";
	}
	
	
	for(int i=0; i<n; i++){
		res += a[i]*city[i];
	}
	
	cout<<res;
	
	return 0;
}
