#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		int t1,t2;
		cin>>t1>>t2;
		v.push_back({t2,t1});
	}
	
	sort(v.begin(),v.end(),greater<pair<int,int>>());
	int now= v[0].first-v[0].second;
	for(int i=1; i<v.size(); i++){
	//	cout<<now<<"\n";
		if(now>v[i].first){
			now = v[i].first-v[i].second;
		}
		else{
			now = now - v[i].second;
		}
	}
	if(now<0){
		cout<<-1;
	}
	else cout<<now;
	return 0;
}
