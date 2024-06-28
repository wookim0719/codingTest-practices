#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<char> stk;
queue<char> q;
char fir;
char las;

int main(){
	cin>>n>>s;
	for(int i=0; i<s.size(); i++){
		stk.push(s[i]);
		q.push(s[i]);
	}
	fir=s[n-1];
	las=s[0];
	int b=0;
	int r=0;
	int b1=0;
	int r1=0;
	
	bool flag= true;
	bool flag2=true;
	while(stk.size()){
		char f= stk.top();
		if(fir==f){
			if(!flag) b++;
		}
		else{
			flag=false;
			r++;
		}
		stk.pop();
	}
	while(q.size()){
		char f= q.front();
		if(las==f){
			if(!flag2) b1++;
		}
		else{
			flag2=false;
			r1++;
		}
		q.pop();
	}
	int ret2=min(b1,r1);
	int ret= min(b,r);
	int ret3=min(ret2,ret);
	cout<<ret3;
	return 0;
}
