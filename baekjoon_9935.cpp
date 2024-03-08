#include <bits/stdc++.h>
using namespace std;
string s,b;
string ret;

int main(){
	cin>>s>>b;

	for(char a:s){
		ret +=a;
		if(ret.size()>=b.size() && ret.substr(ret.size()-b.size(),b.size())==b){
			ret.erase(ret.end() - b.size(), ret.end());
		}
	}
	
	if(ret.size()==0) cout<< "FRULA";
	else
	cout<<ret;
	
	return 0;
}
