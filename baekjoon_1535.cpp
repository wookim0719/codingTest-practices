#include<bits/stdc++.h>
using namespace std;
int n;
int a[21];
int b[21];
int v[100];
int ret;

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=100; j>a[i];j--){
			v[j] = max(v[j],v[j-a[i]]+b[i]);
		}
	}
	
	cout<<v[100];	
	return 0;
}
