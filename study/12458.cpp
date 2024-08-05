#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
vector<int> v;
long long ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	cin>>b>>c;
	
	for(int i=0; i<n; i++){
		int total= v[i];
		total=v[i]-b;
		ret++;
		if(total>0){
		ret+=total/c;
		if(total%c)
		ret++;	
		}
	}
	
	cout<<ret;
	
	
	return 0;
}
