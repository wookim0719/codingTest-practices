#include<bits/stdc++.h>
using namespace std;
int n;
set<string> st;
map<string,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		int idx=0;
		for(int i=0; i<temp.size(); i++){
			if(temp[i]=='.') {
				idx = i;
				break;
			}
		}
		string ext= temp.substr(idx+1,temp.size()-idx);
		mp[ext]++;
		st.insert(ext);
	}
	
	for(string s: st){
		cout<<s<<" "<<mp[s]<<"\n";
	}
	
	return 0;
}
