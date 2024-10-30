#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t;
vector<ll> v;
vector<ll> v2;
int ret;

void go(ll start){
	v.push_back(start);
	if(start==1) return;
	if(start-2>=0)
	go((start-2)/k+1);
	else{
		go(start-1);
	}
	return;
}
void go2(ll start){
	v2.push_back(start);
	if(start==1) return;
	if(start-2>=0)
	go2((start-2)/k+1);
	else{
		go2(start-1);
	}
	return;
}

int findv(ll num){
	int s=0;
	int e=v.size()-1;
	while(s<=e){
		int mid= (s+e)/2;
		if(v[mid]==num){
			return mid;
		}
		else if(v[mid]<num){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	return -1;	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>t;
	
	while(t--){
		ret=0;
		v.clear();v2.clear();
		ll t1,t2;
		cin>>t1>>t2;
		ll start= min(t1,t2);
		ll end = max(t1,t2);
		if(k==1) cout<<end-start<<"\n";
		else{
		go(start);
		go2(end);
		//for(ll i: v2) cout<<i<<" ";
	//	cout<<"\n";
		ll c1=v.size()-1; ll c2=v2.size()-1;
		while(true){
			if(v[c1]!=v2[c2]||c1<0||c2<0){
				break;
			}
			if(c1>=0){
			c1--; 	
			}
			if(c2>=0){
			c2--;
			}
		}
	ret+=c1+1;
	ret+=c2+1;	
	cout<<ret<<"\n";
}
	}
	return 0;
}
