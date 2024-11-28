#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;


int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int t1,t2;
		cin>>t1>>t2;
		v.push_back({t1,t2});
	}	
	sort(v.begin(),v.end());
	
	for(auto i: v){
		cout<<i.first<<" "<<i.second<<"\n";
	}
	
	return 0;
}
