#include<bits/stdc++.h>
using namespace std;
string s;
vector<string> v;
int main(){
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		string temp;
		for(int j=i; j<s.size(); j++){
			temp+=s[j];
		}
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	for(string i: v){
		cout<<i<<"\n";
	}
		
	
	
	return 0;
}
