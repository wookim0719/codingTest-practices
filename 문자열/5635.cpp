#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<string,string>> v;

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		string s;
		string s2,s3,s4;
		cin>>s>>s2>>s3>>s4;
		string temp = s4;
		if(s3.size()==1){
			temp+=('0'+s3);
		}
		else temp+=s3;
		if(s2.size()==1){
			temp+=('0'+s2);
		}
		else temp+=s2;
		v.push_back({temp,s});
	}
	
	sort(v.begin(),v.end());
//	for(auto i:v)cout<<i.first<<i.second<<"\n";
	cout<<v[n-1].second<<"\n"<<v[0].second;
	
	return 0;
}
