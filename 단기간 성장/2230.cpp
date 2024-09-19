#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<int> v;
ll ret=1e16;

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	
	int s=0; 
	int e= s;
	
	while(s!=v.size()-1){
		ll value= v[e]-v[s];
		//cout<<value;
		if(value>=m){
			ret= min(ret,value);
			s++;
		}
		else{
			if(e+1<=v.size()-1)
			e++;
			else s++;
		}	
	}
	
	cout<<ret;
	
	return 0;
}
