#include<bits/stdc++.h>
using namespace std;
vector<string> v;
vector<int> mp[4];
string res;
bool flag1= false;
bool flag2= false;
bool flag3= false;
bool flag4= false;

int main(){
	string temp;
	while(cin>>temp){
		v.push_back(temp);
	}
	
	for(string s: v){
		res+=s;
	}
	queue<char> q;
	for(int i=0; i<res.size(); i++){
		q.push(res[i]);
	}
	while(q.size()){
		char f= q.front();
		q.pop();
		if(f=='U') 
		{
			flag1= true;
			break;
	}
	}
	while(q.size()){
		char f= q.front();
		q.pop();
		if(f=='C') 
		{
			flag2= true;
			break;
	}
	}
	while(q.size()){
		char f= q.front();
		q.pop();
		if(f=='P') 
		{
			flag3= true;
			break;
	}
	}
	while(q.size()){
		char f= q.front();
		q.pop();
		if(f=='C') 
		{
			flag4= true;
			break;
	}
	}
	
	if(flag1&&flag2&&flag3&&flag4)
		cout<<"I love UCPC";
		else 
		cout<<"I hate UCPC";
	return 0;
}
