#include<bits/stdc++.h>
using namespace std;
string s;

void javatoc(){
	for(char c: s){
		if(c<97){
			char k= c+32;
			cout<<'_';
			cout<<k;
		}
		else 
		cout<<c;
	}
	return;
}

void ctojava(){
	bool flag= false;
//	cout<<s<<"\n";
	for(int i=0; i<s.size(); i++){
//	cout<<s[i];
		if(s[i]=='_'){
		//	cout<<flag<<" ";
			if(flag){
				cout<<"Error!";
				return;
			}
			flag= true;
			if(s[i+1]!='_')
			s[i+1]-=32;
		}
		else {
			flag= false;
		//	cout<<flag<<" ";
		}
	}
	for(char c: s){
		if(c=='_')continue;
		else cout<<c;
	}
	return;
}


void check(){
	bool flag= false;
	bool flag2= false;
	if(s[0]=='_'){
		cout<<"Error!";
		return;
	}
	if(s[s.size()-1]=='_'){
		cout<<"Error!";
		return;
	}
	if(s[0]<97){
		cout<<"Error!";
		return;
	}
	for(char c: s){
		if(c<97&&c!='_'){
		//	cout<<c<<"\n";
			flag= true;
		}
		if(c=='_'){
			flag2= true;
		}
	}
	//cout<<flag<<" "<<flag2;
	if(flag&&flag2) cout<<"Error!";
	else if(flag){
	//	cout<<flag;
		javatoc();
	}
	else{
		ctojava();
	}
	
	return;	
}


int main(){
	cin>>s;
	
	check();	
	return 0;	
}
