#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main(){
	cin>>a>>b;
	ll ret = 1e15;
	
	queue<pair<ll,ll>> q;
	q.push({a,0});
	while(q.size()){
		auto f= q.front();
		q.pop();
		if(f.first==b) {
			ret= min(ret,f.second);
			break;
		}
		if(f.first*2<=b)
		q.push({f.first*2,f.second+1});
		if((f.first*10+1)<=b)
		q.push({f.first*10+1,f.second+1});	
	}
	
	if(ret==1e15) cout<<-1;
	else
	cout<<ret+1;
	return 0;
}
