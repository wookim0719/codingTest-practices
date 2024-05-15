#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> o,z;
string res;
int a,b;
queue<int> oq;
queue<int> zq;

int main(){
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='0')z.push_back(i);
		else o.push_back(i);
	}

	int one= o.size()/2;
	int zero = z.size()/2;
	
	z.erase(z.begin()+zero,z.end());
	o.erase(o.begin(), o.begin()+one);
	
//	for(int i:z) cout<<i;
	for(int i: o){
		oq.push(i);
	}
	for(int i: z){
		zq.push(i);
	}
	
	while(oq.size()||zq.size()){
		a=501; b=501;
		if(oq.size())
		a=oq.front();
		if(zq.size())
		b=zq.front();
		if(a<b) {
		oq.pop();
		cout<<"1";	
		}
		else if(b<a){
			cout<<"0";
			zq.pop();
		}
	}
	
	return 0;
}
