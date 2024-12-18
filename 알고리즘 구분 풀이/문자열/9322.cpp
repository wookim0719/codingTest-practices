#include<bits/stdc++.h>
using namespace std;
int t;
int n;
map<string,int> mp;
vector<int> v;
vector<string> v2;

int main(){
	cin>>t;
	
	while(t--){
		v.clear();
		v2.clear();
		string ret[1001];
		mp.clear();
		cin>>n;
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			mp[temp]=i;
		}
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			int next= mp[temp];
			v.push_back(next);
		}
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			v2.push_back(temp); 
		}
		for(int i=0; i<n; i++){
			ret[v[i]] = v2[i];
		}
		for(int i=0; i<n; i++){
			cout<<ret[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
