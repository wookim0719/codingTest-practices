#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
string s;
string g;
int num=INF;

string f1(string temp){
	temp.pop_back();
	return temp;
}

string f2(string temp){
	reverse(temp.begin(),temp.end());
	temp.pop_back();
	//reverse는 반환값이 없다. 
	return temp;
}

void go(string temp,int n){
	//cout<<temp<<"\n";
	if(temp.size()< s.size()) return;
	if(s==temp) {num=n; return;
	}
	if(temp[temp.size()-1]=='A')
	go(f1(temp),n+1);
	if(temp[0]=='B')
	go(f2(temp),n+1);
	return;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>s>>g;
	
	go(g,0);
	
	if(num!=INF) cout<< 1;
	else  cout<<0;
	return 0;
}
