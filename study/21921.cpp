#include <bits/stdc++.h>
using namespace std;

int x,n;
int a[250001];
int res;
int cnt;
int out;
int max_value;


int main(){
	cin>>x>>n;
	for(int i=0; i<x; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		res +=a[i];
	}
	int out = res;
	max_value= out;
	
	for(int i=1; i<=x-n; i++){
		out = out-a[i-1]+a[n+i-1];
		if(out == max_value)cnt++;
		if(out>max_value) cnt= 0;
		max_value= max(max_value,out);
	}
	
	
	if(out ==0 )cout<<"SAD";
	else{
		cout<<max_value<<"\n"<<cnt+1;
	}
	
return 0;	
}
