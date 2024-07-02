#include<bits/stdc++.h>
using namespace std;
int a[10001];
int n;

int main(){
	a[0]=1;
	cin>>n;
	for(int i=3; i>0; i--){
		for(int j=i; j<=10000; j++){
			a[j] = a[j]+ a[j-i];
		}
	}
	for(int i=0; i<n; i++)
	{	int temp;
		cin>>temp;
		cout<<a[temp]<<"\n";
	}	
	return 0;
}
