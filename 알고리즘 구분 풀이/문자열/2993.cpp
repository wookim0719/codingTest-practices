#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
string ret = "zzzzzzzzzzzzzzzz";
int n;

string change_s(string ss){
	for(int i=0; i<ss.size()/2; i++){
		char temp = ss[i];
		ss[i] = ss[ss.size()-1-i];
		ss[ss.size()-1-i]= temp;
	//	cout<<ss[i]<<" "<<ss[ss.size()-1-i]<<"\n";
	}
//	cout<<ss<<"\n";
	return ss;
}

string go(int i, int j){
	string s1= s.substr(0,i+1);
	string s2= s.substr(i+1,j-i);
	string s3= s.substr(j+1,s.size()-j);
	string res;
	res= change_s(s1);
	res+= change_s(s2);
	res+= change_s(s3);

	return res;
}


int main(){
	cin>>s;
	n=s.size();
	for(char c: s){
		v.push_back(c);
	}
	
	for(int i=0; i<n-2;i++){
		for(int j=i+1; j<n-1; j++){
			string res =go(i,j);
		//	cout<<res<<"\n";
			ret= min(res,ret);
		}
	}
	cout<<ret;
	return 0;
}
