#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int a,b;
int now;

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	
	for(int i=0; i<n; i++){
		if(now<v[i].first){
			now = v[i].first+ v[i].second;
		}
		else
		now = now+v[i].second;
			
	}
	
	
	cout<<now;
	
	
	
	return 0;
}
