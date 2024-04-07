#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[101];
ll v[101][2001];


ll cal(int pos, ll res){
	pos++;
	if(res<0 ||res>20) return 0;
	if(pos == n-1){
		if(res == a[n-1]){
			return 1;
		}
		return 0;
	} 
	ll &ret = v[pos][res];
	if(ret) return v[pos][res];
	
	ret+=cal(pos, res+a[pos]);
	ret+=cal(pos, res-a[pos]);
	return ret;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	ll r =cal(0,a[0]);
	
	cout<<r;
	return 0;
}
