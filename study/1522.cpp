#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int ret=987654321;

int main(){
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='a')
		cnt++;
	}
	int sp=0;
	int ep=cnt-1;
	if(cnt==0){
		ret=0;
	}
	while(true){
		//cout<<sp<<" "<<ep<<" "<<ret<<"\n";
		int n=0;
		if(sp<=ep)
		for(int i=sp; i<=ep; i++){
			if(s[i]=='b')
			n++;
		}
		else{
			for(int i=sp; i<s.size(); i++){
				if(s[i]=='b')
				n++;	
			}
			for(int i=0; i<=ep; i++){
				if(s[i]=='b')
				n++;	
			}
		}
		ret=min(n,ret);
		sp++;
		ep=((ep+1)%s.size());
		if(sp==s.size()) break;
	}
	
	cout<<ret;
	return 0;
}
