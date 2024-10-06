#include<bits/stdc++.h>
using namespace std;
float n,m;

int main(){
	cin>>n>>m;
	
	if(n>m) cout<<">";
	else if(n<m) cout<<"<";
	else{
		cout<<"==";
	}
}
