#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
map<string,int> mp;
int ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
	}	
	
	for(int i=0; i<n; i++){
		if(mp[v[i]]){
			continue;
		}
		else{
			string temp;
			for(int j=0; j<v[i].size(); j++){
				temp.clear();
				temp+= v[i].substr(j,v[i].size());
				temp+= v[i].substr(0,j);
				mp[temp]++;
			}
			ret++;
		}
	}
	
	cout<<ret;
	return 0;
}
