#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> res;
int ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int temp=0;
	for(int i=0; i<n; i++){
	   temp+= v[i];
	   //cout<<temp<<"\n";
	   ret+=temp;
	}
	
	cout<<ret;
	
	return 0;
}
