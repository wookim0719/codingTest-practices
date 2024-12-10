#include<bits/stdc++.h>
using namespace std;
string s;
string s2;
int cnt;

int main(){
	getline(cin,s);
	getline(cin,s2);
	while(true){
	//	cout<<s<<"\n";
		auto pos = s.find(s2);
		if(pos == string::npos){
			break;
		}
		else{
			s = s.substr(pos+s2.size());
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
