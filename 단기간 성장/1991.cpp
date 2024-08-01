#include<bits/stdc++.h>
using namespace std;
int n;

vector<char> v[28];


void pre(int f){
	char r=f+'A';
	cout<<r;
	if(v[f][0]!='.'){
		pre(v[f][0]-'A');
	}
	if(v[f][1]!='.'){
		pre(v[f][1]-'A');
	}
	return;
}

void in(int f){
	if(v[f][0]!='.'){
		in(v[f][0]-'A');
	}
	char r=f+'A';
	cout<<r;
	if(v[f][1]!='.'){
		in(v[f][1]-'A');
	}
	return;
}

void post(int f){
	if(v[f][0]!='.'){
		post(v[f][0]-'A');
	}
	if(v[f][1]!='.'){
		post(v[f][1]-'A');
	}
	char r=f+'A';
	cout<<r;
	return;
}



int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		char temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		v[temp1-'A'].push_back(temp2);
		v[temp1-'A'].push_back(temp3);
	}	
	
	pre(0);
	cout<<"\n";
	in(0);
	cout<<"\n";
	post(0);
	
	
	return 0;
}
