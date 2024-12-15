#include<bits/stdc++.h>
using namespace std;
string s;
string temp;
map<string,int> mp;
int ret;
int main(){
	cin>>s;
	for(int i=0; i<s.size(); i++){
		temp.clear();
		for(int j=i; j<s.size(); j++){
			temp+=s[j];
			if(mp[temp]==0){
				mp[temp]++;
				ret++;
			}
		}
	}
	cout<<ret;
	return 0;
}
