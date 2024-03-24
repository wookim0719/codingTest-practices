#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> v;

int main(){
	cin>>t;
	
	while(t--){
		int n =0;
		int m =0;
		int cnt=0;
		int index=0;
		cin>>n>>m;
		vector<int> a;
		vector<int> b;
		for(int i=0; i<n; i++){
			int temp;
			cin>>temp;
			a.push_back(temp);
		}
		for(int j=0; j<m; j++){
			int temp;
			cin>>temp;
			b.push_back(temp);		}
		
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		for(int i=0; i<m; i++){
			int value = b[i];
		int	lo= 0;
		int hi= n-1;
		int mid =0;
			while(lo<=hi){
				mid = (lo+hi)/2;
				if(a[mid]>value){
					hi = mid-1;
					if(a[hi]==value) {
					mid = hi;
					break;	
					}
				}
				else lo = mid+1;	
			}
			cout<<mid<<"\n";
		}
	v.push_back(cnt);
	}
	
	for(int i:v)
	cout<<i<<"\n";
	
	return 0;
}
