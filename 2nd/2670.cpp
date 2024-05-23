#include<bits/stdc++.h>
using namespace std;
int n;
double a[10001];
double ret;

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	double temp=1;
	for(int i=0; i<n; i++){
		if((temp*a[i])<1){
			ret= max(ret,a[i]);
			temp=1;
		}
		else {
			temp*=a[i];
			ret= max(temp,ret);
		}
	}

	
	printf("%.3lf",ret);
	return 0;
}
