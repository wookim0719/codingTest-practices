#include<bits/stdc++.h>
using namespace std;
string s;
string res;
int main(){
	cin>>s;
	stack<char> stk;
	
	for(int i=0; i<s.size(); i++){
	 if(s[i]=='('){
			stk.push('(');
		}
		else if(s[i]==')'){
			while(stk.size()){
				char temp=stk.top();
				if(temp=='('){
					stk.pop();
					break;
				}
				else{
					stk.pop();
					res+=temp;
				}
			}
		}
		else if(s[i]=='*'||s[i]=='/'){
			while(stk.size()){
				char temp3= stk.top();
				if(temp3=='*'||temp3=='/'){
					stk.pop();
					res+=temp3;
				}
				else break;
			}
			stk.push(s[i]);	
		}
		else if(s[i]=='+'||s[i]=='-'){
			while(stk.size()){
				char temp2 = stk.top();
				if(temp2=='*'||temp2=='/'||temp2=='+'||temp2=='-'){
					stk.pop();
					res+=temp2;
				}
				else break;
			}
			stk.push(s[i]);
		}
		else{
			res+=s[i];
		}
	}	
	while(stk.size()){
		char temp =stk.top();
		stk.pop();
		res+=temp;
	}

	cout<<res;
	return 0;
}
