#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
vector<int> v2;
string ret;
int main(){
	cin>>s;
	for(int i=0; i<s.size(); i++){
		v.push_back(s[i]);
	}
	sort(v.begin(),v.end());
	 bool flag=false;
	 do{
	 	string ts="";
	 	for(char i: v){
	 		ts+=i;
		 }
		 if(ts[0]=='0') continue;s
	//	 cout<<ts<<"\n";
		 if(flag){
		 	ret = ts;
		 	break;
		 }
		 if(ts==s){
		 	flag = true;
		 }
		 
	 }
	 while(next_permutation(v.begin(),v.end()));
	
	if(ret!=s&&ret!="") 
	cout<<ret;
	else cout<<0;
	return 0;
}
