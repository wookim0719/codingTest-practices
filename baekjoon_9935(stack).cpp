#include <bits/stdc++.h>
using namespace std;
string s,b;
string ret;


int main(){
	cin>>s>>b;
	
	stack<char> stk;
	for(char c: s){
		stk.push(c);
		if(stk.size()>= b.size() && stk.top() == b[b.size() -1]){
			string ss= "";
			for(char i: b){
				ss += stk.top();
				stk.pop();
			}
			reverse(ss.begin(), ss.end());
			if(b!= ss){
				for(int i : ss){
					stk.push(i);
				}
			}
		}
	}
	 if(stk.size() == 0){
        cout << "FRULA\n";
    }else{
        while(stk.size()){
            ret += stk.top(); stk.pop();
        }
        reverse(ret.begin(), ret.end()); 
        cout << ret << "\n";
    }
	return 0;
}
