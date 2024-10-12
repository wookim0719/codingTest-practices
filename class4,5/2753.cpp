#include<bits/stdc++.h>
using namespace std;
int n;
int ret;
int main(){
	cin>>n;
	
	if((n%4==0&&n%100!=0)||n%400==0)
	ret=1;
	else ret=0;
	cout<<ret;
	return 0;
}
