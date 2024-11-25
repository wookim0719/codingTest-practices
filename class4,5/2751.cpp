#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<"\n";
	}
	
	return 0;
}
