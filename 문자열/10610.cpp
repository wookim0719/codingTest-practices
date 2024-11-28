#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int sum=0;
	for(int i=0; i<s.size(); i++){
		sum+= s[i]-'0';
		mp[s[i]-'0']++;
	}
	
	if(sum%3||mp[0]==0) cout<<-1;
	else{
		for(int i=9; i>=0; i--){
			for(int j=0; j<mp[i]; j++){
				cout<<i;
			}
		}
	}
	
	return 0;
}
