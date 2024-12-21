#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	stack<char> stk;
	for(int i=0; i<s.size(); i++){
		if(stk.size()){
			char f= stk.top();
		//	cout<<f<<" "<<s[i]<<"\n";
			if(f=='('&&s[i]==')'){
				stk.pop();
			}
			else
			stk.push(s[i]);
		}
		else
		stk.push(s[i]);
	}
	
//	while(stk.size()){
//		cout<<stk.top();
//		stk.pop();
//	}
	
	cout<<stk.size()<<"\n";
	
	return 0;
}
