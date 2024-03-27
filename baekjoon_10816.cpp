#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[500001];
vector<int> a;


int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	
	sort(a.begin(), a.end());
	
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>b[i];
	}
	int k=0;
	while(m--){
		int value = b[k];
		auto start = lower_bound(a.begin(),a.end(), value);
		auto end = upper_bound(a.begin(),a.end(),value);
		cout<<end-start<<" ";
		k++;
	}
	
	
	
	return 0;
}
