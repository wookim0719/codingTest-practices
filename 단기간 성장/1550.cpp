#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int ret;
int main(){
	string s;
	cin>>s;
	mp['A']=10;
	mp['B']=11;
	mp['C']=12;
	mp['D']=13;
	mp['E']=14;
	mp['F']=15;
	for(int i=s.size()-1; i>=0; i--){
		char c= s[i];
		if(c>='A'&&c<='F'){
			ret += pow(16,s.size()-1-i)*mp[c];
		}
		else{
			ret += pow(16,s.size()-1-i)*(c-'0');
		}
	}
	cout<<ret;
	
	return 0;
}
