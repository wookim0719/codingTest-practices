#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	for(int i=0; i<3; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	for(int i: v){
		cout<<i<<" ";
	}
	
	return 0;
}
