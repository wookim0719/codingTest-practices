#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a,b;
ll ret;
vector<pair<int,int>> v;
vector<ll> vv;
priority_queue<int> pq;
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	for(int i=0;i<k; i++){
		int temp;
		cin>>temp;
		vv.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	sort(vv.begin(),vv.end());
	
	int j=0;
	for(int i=0; i<k; i++){
		while(j<n && v[j].first <= vv[i])
		pq.push(v[j++].second);
		if(pq.size()){
			ret += pq.top();		
			pq.pop();
		}
	}
	
	cout<<ret;
	
	return 0;
}
