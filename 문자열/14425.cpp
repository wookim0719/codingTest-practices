#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> mp;
int cnt;
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		mp[temp]++;
	}
	
	for(int i=0; i<m; i++){
		string temp2;
		cin>>temp2;
		if(mp[temp2])
		cnt++;	
	}
	cout<<cnt;
	return 0;
}
