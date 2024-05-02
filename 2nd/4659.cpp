#include <bits/stdc++.h>
using namespace std;


bool check_mo(string t){
	bool flag =false;
	for(int i=0; i<t.size(); i++){
		if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u')
			flag=true;
	}
	return flag;
	}
	
bool check_moeum(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
	
	return true;}
	
	else{
	
	return false;}
}

bool check_triple(string t){
	bool flag= true;
	int num=0;
	int num2=0;
	for(int i=0; i<t.size(); i++){
		if(check_moeum(t[i]))
		{
			num++;
			num2=0;
		}
		else{
			num=0;
			num2++;
		}
		if(num2>=3||num>=3)flag = false;
		
	}
	return flag;
}

bool check_double(string t){
	bool flag= true;
	char last =t[0];
	for(int i=1; i<t.size(); i++){
		if(t[i]==last&&t[i]!='e'&&t[i]!='o') flag = false;
		last= t[i];
	}
	return flag;
}



int main(){
	while(true){
		int con_num=0;
		string s;
		cin>>s;
		if(s=="end") break;
		if(!check_mo(s)) cout<<'<'<<s<<'>'<<" is not acceptable."<<"\n";
		else if(!check_triple(s)){
			cout<<'<'<<s<<'>'<<" is not acceptable."<<"\n";
		}
		else if(!check_double(s)){
			cout<<'<'<<s<<'>'<<" is not acceptable."<<"\n";
		}	
		else
		cout<<'<'<<s<<'>'<<" is acceptable."<<"\n";
	}
	
	return 0;
}
