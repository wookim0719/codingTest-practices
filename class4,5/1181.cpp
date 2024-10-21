#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>> v; 
map<string,int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		if(mp[temp])continue;
		else{
		mp[temp]=1;
		pair<int,string> temp2;
		temp2= {temp.size(),temp};
		v.push_back(temp2);	
		}
	}
	sort(v.begin(),v.end());
	
	for(auto s: v){
		cout<<s.second<<"\n";
	}
	
	return 0;
}
