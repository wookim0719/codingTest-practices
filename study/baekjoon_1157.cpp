#include <bits/stdc++.h>
using namespace std;
int a[30];
int max_val;
int flag;
int final;


int main(){
	string s;
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]>96)
		a[s[i]-97]++;
		else
		a[s[i]-65]++;
		
	}
	
	
	for(int i=0; i<30; i++){
		
		if(max_val== a[i]){
			flag=1;		
		}
		if(max_val<a[i]){
		flag =0;		
		max_val = a[i];
		final = i;
	}
}

if(flag!=1)
cout<< static_cast<char>(final+65);
else
cout<<"?";
	return 0;
}
