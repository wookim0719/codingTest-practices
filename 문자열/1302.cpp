#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
set<string> st;
string res;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		st.insert(temp);
		mp[temp]++;
	}
	int ret=0;
	for(string s: st){
		if(mp[s]>ret){
			res= s;
			ret= mp[s];	
		}
	}
	
	
	cout<<res;
	return 0;
}
