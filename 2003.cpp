#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
int cnt;
int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int s=0;
	int e=1;
	int sum=v[0];
	while(s<=e&&e<=n&&s<n){
		if(sum<=m){
			if(sum==m) cnt++;
			if(e<n)
			sum+=v[e];
			e++;
		}
		else{
			sum-=v[s];
			s++;
		}
	}
	cout<<cnt;
	
	
	return 0;
}
