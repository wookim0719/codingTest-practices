#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,s2;
int t;
vector<pair<char,int>> v; 
vector<pair<char,int>> temp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	cin>>s>>s2;
	cin>>t;
	for(int i=s.size()-1; i>=0; i--)
	v.push_back({s[i],0});
	for(int i=0; i<s2.size(); i++)
	v.push_back({s2[i],1});
	int tt=0;
	while(true){
		if(tt==t)break;
		temp.clear();
		for(int i=0; i<v.size(); i++){
		if(v[i].second!=v[i+1].second&&v[i].second==0&&i!=v.size()-1){
			temp.push_back(v[i+1]);
			temp.push_back(v[i]);
			i+=1;
		}
		else
		temp.push_back(v[i]);
		}
		v= temp;
		tt++;
	}
	
	for(int i=0; i<v.size(); i++){
		cout<<v[i].first;
	}
		
	return 0;
}
