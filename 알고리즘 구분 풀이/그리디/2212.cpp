#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v;
vector<int> gap;
int ret;
int cnt;
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for(int i=1; i<n; i++){
		gap.push_back(v[i]-v[i-1]);
	}
	sort(gap.begin(),gap.end());
//	for(int i: gap) cout<<i;
	if(gap.size()<=k) ret= 0;
	else{
			for(int i=0; i<=gap.size()-k; i++){
	//	cout<<gap[i];
		ret+=gap[i];
	}
	
	}

	cout<<ret;
	return 0;
}
