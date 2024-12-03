#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
map<char,int> mp2;
string s;

bool flag = false;
int main(){
	mp2['P']=13;
	mp2['H']=13;
	mp2['K']=13;
	mp2['T']=13;
	cin>>s;
	for(int i=0; i<s.size(); i+=3){
		string temp = s.substr(i,3);
		if(mp[temp]) {
			flag= true;
			cout<<"GRESKA";
			break;
		}
		else{
			mp[temp]++;
			mp2[temp[0]]--;
		}
	}
	if(!flag){
		cout<<mp2['P']<<" ";
		cout<<mp2['K']<<" ";
		cout<<mp2['H']<<" ";
		cout<<mp2['T']<<" ";
	}
	
	return 0;
}
