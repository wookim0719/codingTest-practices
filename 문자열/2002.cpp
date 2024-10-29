#include<bits/stdc++.h>
using namespace std;
int n;
map<int,string> mp;
map<string,int> mp2;
vector<string> v;
int ret;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		mp[i]=s;
	}
	
	for(int j=0; j<n; j++){
		string s;
		cin>>s;
		mp2[s]=j;
		v.push_back(s);
	}
	
	for(int i=n-1; i>=0; i--){
		string s=mp[i];
		if(mp2[s]==i) continue;
		for(int j=mp2[s]; j<n-1; j++){
			mp2[v[j]]=j+1;
			mp2[v[j+1]]=j;
			string tmp=v[j];
			v[j]=v[j+1];
			v[j+1]=tmp;	
		}
		ret++;
	}
	
	cout<<ret;
	return 0;
}
