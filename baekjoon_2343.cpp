#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100004];
int max_value;
int ret;
int big;
int sum;

bool check(int mid){
	if(mid<big) return false;
	int num =0;
	int sum2 =0;
	for(int i=0; i<n; i++){
		if(sum2+a[i]>mid){
			num++;
			sum2=a[i];
		}
		else
			sum2 +=a[i];
	}
	num++;
	
	return num<=m;
}

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		cin>> a[i];
		sum += a[i]; 
		big = max(big,a[i]);
		max_value=max(max_value, sum);
	}
	int lo=1; 
	int hi= max_value;
	
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			ret = mid;
			hi= mid-1;
		}
		else
			lo = mid+1;		
	}
	
	cout<<ret;
	return 0;
}
