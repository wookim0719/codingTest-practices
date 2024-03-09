#include <bits/stdc++.h>
using namespace std;

int h,w,n,m;
int a,b;
int ret;

int main(){
	
	cin>>h>>w>>n>>m;
	
	a= h/(n+1);
	b= w/(m+1);
	
	if(h%(n+1))
	a++;
	if(w%(m+1))
	b++;
	ret = a*b;
	
	cout<<ret;

	return 0;
}
