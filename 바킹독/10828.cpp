#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	stack<int> stk;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		if(temp=="push"){
			int t1;
			cin>>t1;
			stk.push(t1);
		}
		else if(temp=="pop"){
			if(stk.size()){
				cout<<stk.top()<<"\n";
				stk.pop();
			}
			else cout<<-1<<"\n";
		}
		else if(temp=="size"){
			cout<<stk.size()<<"\n";
		}
		else if(temp=="empty"){
			if(stk.empty()){
				cout<<1<<"\n";
			}
			else cout<<0<<"\n";
		}
		else{
			if(stk.size())
			cout<<stk.top()<<"\n";
			else cout<<-1<<"\n";
		}
	}
	return 0;
}
