#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<pair<int,int>> v;
pair<int,int> p1= {1,1};
pair<int,int> p2;
int ret;

int compare(int y,int x){
	int value1=0;
	int value2=0;
	
	value1 = abs(p1.first-y)+ abs(p1.second-x);
	value2 = abs(p2.first-y)+ abs(p2.second-x);
	if(value1>value2) ret+=value2;
	else ret+=value1;
	
	return (value1>value2)? 1 :0;
}

int main(){
	cin>>n;
	p2 = {n,n};
	cin>>m;
	for(int i=0; i<m; i++){
		int c,d;
		cin>>c>>d;
	int temp=compare(c,d);
	if(temp==0){
		p1.first = c;
		p1.second = d;
		a.push_back(1);
	}
	else{
		p2.first=c;
		p2.second=d;
		a.push_back(2);
	}
	}
	cout<<ret<<"\n";
	for(int i : a)
	cout<<i<<"\n";
	return 0;
}
