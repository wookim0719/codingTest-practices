#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100001];
int ret;



int main(){
	cin>>n>>k;

	for(int i=0; i<n; i++){
		int temp,temp2;
		cin>>temp>>temp2;
		for(int j= k; j>=temp ; j--){
			a[j] = max(a[j], a[j-temp]+temp2);
		}
	}
	

	cout<<a[k];
	
	return 0;
}
