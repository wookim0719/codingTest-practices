#include<bits/stdc++.h>
using namespace std;
string s;
string ret;
int main(){
	getline(cin,s);
	stack<char> stk;
	queue<char> q;
	bool flag = false;
	for(int i=0; i<s.size(); i++){
		if(s[i]==' '&&!flag){
			while(stk.size()){
				char f= stk.top();
				stk.pop();
				cout<<f;
			}
			cout<<' ';
		}
		else if(s[i]=='<'){
			while(stk.size()){
				char f= stk.top();
				stk.pop();
				cout<<f;
			}
			flag= true;
			q.push(s[i]);
		}
		else if(s[i]=='>'){
			while(q.size()){
				cout<<q.front();
				q.pop();
			}
			cout<<'>';
			flag= false;
		}
		else if(flag){
			q.push(s[i]);
		}
		else{
		//	cout<<s[i]<<"\n";
			stk.push(s[i]);
		}
	}
	while(stk.size()){
				char f= stk.top();
				stk.pop();
				cout<<f;
			}

	return 0;
}
