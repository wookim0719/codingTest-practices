#include<bits/stdc++.h>
using namespace std;

int n;
int len;
string s;
int cnt;
int ret;

int main(){
	cin>>n>>len;
	cin>>s;
	
	string pre="";
	for(int i=0; i<s.size();i++){
		if(pre==""){
			if(s[i]=='I')
			pre+='I';
		}
		else{
			if(pre[pre.size()-1]!=s[i]){
				pre+=s[i];
				if(pre.size()>=3&&pre[pre.size()-3]=='I'&&pre[pre.size()-2]=='O'&&pre[pre.size()-1]=='I')
				cnt++;
			}
			else{
				if(n<=cnt)
				ret+=(1+cnt-n);
				cnt=0;
				pre=s[i];
			}
		}
	}
	if(n<=cnt)
	ret+=(1+cnt-n);
	
	
	cout<<ret;
	
	
	return 0;
}
