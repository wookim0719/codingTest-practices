#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
int t;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		mp[temp]++;
	}
	cin>>t;
	
	cout<<mp[t];
	
	return 0;
}
