#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int> a;
int ret;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>> temp;
		a.push_back(temp);
	}
	cin>>x;
	sort(a.begin(),a.end());
	int l=0, r = n-1;
	while(l<r){
		if(a[l]+a[r]==x){
			r--; 
			ret++;
		}
		else if(a[l]+a[r]>x) r--;
		else if(a[l]+a[r]<x) l++;
	}
	
	cout<<ret;	
	
	return 0;
}
