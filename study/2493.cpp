#include<bits/stdc++.h>
using namespace std;
map <int,int> mp;
stack<pair<int,int>> stk;
int n;
vector<pair<int,int>> v;
int main(){
	cin>>n;
	for(int i=0 ;i<n; i++){
		int temp;
		cin>>temp;
		v.push_back({temp,i+1});
	}
	
	for(int i=n-1; i>=0; i--){
		//cout<<v[i].first<<"\n";
		while(stk.size()){
			pair<int,int> t= stk.top();
		//	cout<<t.first;
			if(t.first<=v[i].first){
			mp[t.second] = v[i].second;
			stk.pop();
			}
			else break;
		}
		stk.push({v[i].first,v[i].second});
	}
	
	for(int i=1; i<=n; i++){
		cout<<mp[i]<<" ";	
	}
	return 0;
}
