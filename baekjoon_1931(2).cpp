#include <bits/stdc++.h>
using namespace std;

int n,a,b;
vector<pair<int,int>> v;
int last;
int cnt;

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a>>b;
		v.push_back({b,a});
	}
	sort(v.begin(),v.end());
	
	for(int i=0; i<n; i++){
		if(last<=v[i].second){
			last = v[i].first;
			cnt++;
		}	
	}
	
	cout<<cnt;
	return 0;
}
