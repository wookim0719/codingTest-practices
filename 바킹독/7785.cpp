#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
vector<string> ret;
int main(){
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t2=="enter"){
			mp[t1]++;
		}
		else{
			mp[t1]--;
			}
	}
	for(auto t: mp){
		if(t.second>0)
		ret.push_back(t.first);
	}
	
	sort(ret.begin(),ret.end(),greater<string>());
	
	for(string t: ret)
	cout<<t<<"\n";
	
	return 0;
}
