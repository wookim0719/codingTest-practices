#include <bits/stdc++.h>
using namespace std;
int n=0;
int cnt=1;
int a=1;

int main(){
	cin>>n;
	
	while(true){
		a= a + cnt*6;	
		if(n<=a)
		break;	
		else
		cnt++;	
	}
	if(n==1) cout<<1;
	else
	cout<<cnt+1;	
	return 0;
}
