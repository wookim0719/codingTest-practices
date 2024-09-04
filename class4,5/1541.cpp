#include<bits/stdc++.h>
using namespace std;
string s;
	vector<char> oper;
	vector<int> v;
	int ret=987654321;
	
	int go(int y, int x){
		int sum=v[y];
		int sum2=0;
		for(int i=y; i<x; i++){
			if(oper[y]=='+'){
				sum+=v[i+1];
			}
			else{
				sum-=v[i+1];
			}	
		}
		if(y>0){
			if(oper[y-1]=='-'){
				sum= -sum;
			}
		}
		for(int i=0; i<y; i++){
			if(i==0) sum2=v[i];
			else{
				if(oper[i]=='+') sum2+=v[i];
				else{
					sum2-=v[i];
				}
			}
		}
		for(int i=x+1; i<v.size(); i++){
			if(oper[i-1]=='+') sum2+=v[i];
			else{
				sum2-=v[i];
			}
		}
	//00009-00009	cout<<y<<" "<<x<<" "<<sum<<" "<<sum2<<"\n";
		return sum+sum2;
	}
	
int main(){
	
	cin>>s;
	int no= 0;
	string temp="";
	while(true){
		if(no==s.size()) break;
		char f= s[no];
		if(f=='+'||f=='-'){
			int vv=0;
			for(int i=0; i<temp.size(); i++){
				vv= vv*10+(temp[i]-'0');
			}
			v.push_back(vv);
			temp="";
			oper.push_back(f);
		}
		else{
			temp+=f;
		}
		no++;
	}
	int vv=0;
	for(int i=0; i<temp.size(); i++){
		vv= vv*10+(temp[i]-'0');
	}
	v.push_back(vv);
	ret = v[0];
	int ret2=0;
	for(int i=0;i <oper.size(); i++){
		if(oper[i]=='+'){
			if(ret2){
				ret2+=v[i+1];
			}
			else{
				ret+=v[i+1];
			}
		}
		else{
			if(ret2){
				ret -=ret2;
				ret2=v[i+1];
			}
			else{
				ret2=v[i+1];
			}
		}
	}
	ret -=ret2;

	cout<<ret;
	
	return 0;
}
