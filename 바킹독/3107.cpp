#include<bits/stdc++.h>
using namespace std;
string s;
string ret;
int main(){
	queue<char> q;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(i==s.size()-1){
			if(s[i]!=':'){
			if(q.size()<4){
//				cout<<q.size()<<"\n";
				for(int i=0; i<3-q.size(); i++){
					ret+='0';
				}
			}
				while(q.size()){
				ret+=q.front();
					q.pop();
			}
			ret+=s[i];	
			}

		}
		else{
		if(s[i]!=':'){
			q.push(s[i]);	
		}
		else{
			bool flag=false;
			if(q.size()){
				flag=true;
				if(q.size()!=4){
					for(int i=0; i<4-q.size(); i++){
						ret+='0';
					}
				}
					while(q.size()){
						ret+=q.front();
						q.pop();
					}
					ret+=':';	
			}
			 if(s[i+1]==':'){
				int cnt=0;
				if(i+1!=s.size()-1){
					for(int j=0; j<s.size(); j++){
					if(j!=i&&j!=i+1){
						if(s[j]==':')cnt++;
					}
				}
				if(flag)cnt++;
				for(int k=0; k<7-cnt; k++){
					ret+="0000:";
				}	
				}
				else{
				for(int j=0; j<s.size(); j++){
					if(j!=i&&j!=i+1){
						if(s[j]==':')cnt++;
					}
				}
				for(int k=0; k<7-cnt; k++){
					if(k!=6-cnt)
					ret+="0000:";
					else {
						ret+="0000";
					}
				}	
				}
			}
			}
	}
		}
		
		cout<<ret;

	return 0;
}
