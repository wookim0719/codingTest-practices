#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;

int main(){
	cin>>n;
	while(true){
		if(n<=1) break;
		if(n%2)cnt++;
		n= n/2;
	}
	if(n==1)cnt++;
	
	cout<<cnt;
	
	
	return 0;
}
