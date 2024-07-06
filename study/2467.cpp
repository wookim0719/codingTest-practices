#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> v;
ll a,b;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int s=0;
	int e=v.size()-1;
	ll ret= 1e16;
	
	while(s!=e){
		int t= v[s]+v[e];
		if(t==0){
			a=v[s];
			b=v[e];
			break;
		}
		else if(t<0){
			if(abs(t)<ret){
			ret=abs(t);
			a= v[s];
			b= v[e];	
			} 
			s++;
		}
		else if(t>0){
			if(abs(t)<ret) {
			ret=abs(t);	
			a= v[s];
			b= v[e];
			}
			e--;
		}
	}
	
	cout<<a<<" "<<b;
	return 0;
}
