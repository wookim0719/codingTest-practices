#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int a[10001];
ll ret= 1e16;
vector<int> v;

bool check(ll num){
	ll cnt=0;
	for(int i=0; i<m; i++){
		cnt+= num/a[i];
	}
	if(cnt>=n)return true;
	else return false;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		cin>>a[i];
	}
	
	if(n<=m){
		cout<<n;
		return 0;
	}
	
	n = n-m;
	ll lo=1;
	ll hi=1e16;
	ll mid=0;
	
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(check(mid)){
			hi=mid-1;
			ret= min(ret,mid);
		}
		else{
			lo=mid+1;
		}
	}
	//cout<<ret<<"\n";
	ll value=0;
	for(int i=0; i<m; i++){
		value += ret/a[i];
	}
	
	ll prev =ret-1;
	ll total=0;
	while(true){
		total=0; 
		for(int i=0; i<m; i++){
			total+=prev/a[i];
		}
		if(total<value) break;
		prev--;
	}
//	prev =ret-1;
//	total=0;
//	for(int i=0; i<m; i++){
//		total += prev/a[i];
//	}
	//prev는 변화하는 전 시간, 이때를 기준으로 몇 명이 타고 마지막은 몇 번재를 타는지 계산  
	ll order= n-total;
//	cout<<total<<" "<<order<<"\n";
	for(int i=0; i<m; i++){
		if(ret%a[i]==0) v.push_back(i);
	}
//	for(int i:v)cout<<i<<" "<<"\n";
	cout<<v[order-1]+1;

	return 0;
}
