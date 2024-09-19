#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
vector<int> v;
int hh;
int ret;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
		hh=max(hh,temp);
	}
	sort(v.begin(),v.end());
	int l=0;
	int h=hh;
	
	while(l<=h){
		int mid= (l+h)/2;
		ll sum=0;
		for(int i=v.size()-1; i>=0; i--){
			if(v[i]>mid){
				sum+=v[i]-mid;
				if(sum>m)break;
			}
			else break;
		}
		if(sum>=m){
			ret= max(ret,mid);
			l=mid+1;
		}
		else{
			h=mid-1;
		}
	}
	cout<<ret;
	return 0;
}
