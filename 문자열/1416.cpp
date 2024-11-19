#include<bits/stdc++.h>
using namespace std;
int t;
int ret;
map<char,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	for(int i=0; i<t; i++){
		mp.clear();
		string s;
		cin>>s;
		bool flag = true;
		char pp ='A';
		for(char c:s){
			if(mp[c]==0){
				mp[c]=1;
				pp = c;
			}
			else{
				if(pp!= c){
				pp=c;
				flag= false;
				break;	
				}
			}
		}
		if(flag) ret++;
	}	
	cout<<ret;
	return 0;
}
