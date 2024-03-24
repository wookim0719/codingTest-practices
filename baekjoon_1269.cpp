#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<int> b;
int cnt;

int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);	
	}
	for(int j=0; j<m; j++){
		int temp;
		cin>>temp;
		b.push_back(temp);	
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
		for(int i=0; i<n; i++){
			//	cout<<a[i]<<"\n";
			int flag=0;
			int value= a[i];
			int lo= 0;
			int hi= m-1;
			while(lo<=hi){
				int mid= (lo+hi)/2;
				if(b[mid]>=value){
					if(b[mid]== value) {
						flag=1;
						break;
					}
					else hi=mid-1;
				}
				else
				lo= mid+1;
			}
			if(flag) {
				cnt++;
		}
	}
	
	cout<<(n+m-2*cnt);
	
	return 0;
}
