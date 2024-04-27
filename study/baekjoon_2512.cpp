#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int max_value;
int limit;
int budget;


int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		max_value = max(max_value,a[i]);
	}
	cin>>budget;
	
	limit = max_value;
	while(true){
		int sum=0;
		for(int i=0; i<n; i++){
			if(a[i]<=limit) sum += a[i];
			else sum+=(limit);
		}
		if(sum<=budget){
			break;
		}
		limit--;	
	}
	cout<<limit;
	
	return 0;
}
