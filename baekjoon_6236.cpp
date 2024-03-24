	#include<bits/stdc++.h>
	using namespace std;
	int n,m,ret;
	int max_v ;
	int a[100001];
	int big;
	int sum;
	
	bool check(int mid){
		if(mid<big) return 0;
		int cnt =0;
		int wallet =0;
		for(int i=0; i<n; i++){
			if(a[i]>wallet){
			cnt++;
			wallet = mid-a[i];
			}
			else
			wallet -= a[i];
		}
	
		
		return cnt<=m;
	}
	
	
	int main(){
		cin>>n>>m;
		
		for(int i=0; i<n; i++){
			cin>>a[i];
			big = max(big,a[i]);
			sum += a[i];
		}
		int lo=0;
		int hi=sum;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			if(check(mid)){
				ret = mid;
				hi = mid-1;
			}
			else lo = mid+1;
			
		}
		
		cout<<ret;
		
		
		return  0;
	}
