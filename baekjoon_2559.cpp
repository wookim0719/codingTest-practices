#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int k;
	int input;
	int ret=-10000004;
	cin>>n;
	cin>>k;
	vector<int> arr(100000);
	for(int i=1; i<=n; i++){
		cin>> input;
		arr[i] = arr[i-1] + input;
	}
	
	for(int i=k; i<=n; i++){
		ret = max(ret,arr[i]-arr[i-k]);
	}
	cout<< ret;
	

	
	return 0;
}
