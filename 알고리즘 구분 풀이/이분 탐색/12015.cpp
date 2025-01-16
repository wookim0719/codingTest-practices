#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> res;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	res.push_back(v[0]);
	for(int i=1;i <n; i++){
		if(v[i]>res[res.size()-1]){
			res.push_back(v[i]);
		}
		else{
			int pos = lower_bound(res.begin(), res.end(),v[i]);
			res[pos] = v[i];
		}
	
	}
	
	
	return 0;
}
