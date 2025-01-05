#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		if(temp<m){
			v.push_back(temp);
		}
	}
	//sort(v.begin(),v.end());
	
	for(int i: v){
		cout<<i<<" ";
	}
	return 0;
}
