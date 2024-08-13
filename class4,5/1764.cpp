#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> mp;
vector<string> v;
int main(){
	cin>>n>>m;
	
	for(int i=0 ;i<n; i++){
		string temp;
		cin>>temp;
		mp[temp]++;
	}
	
	for(int i=0; i<m; i++){
		string temp;
		cin>>temp;
		if(mp[temp]){
			v.push_back(temp);
		}
	}
	
	sort(v.begin(),v.end());
	
	cout<<v.size()<<"\n";
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<"\n";
	}
	
	
	return 0;
}
