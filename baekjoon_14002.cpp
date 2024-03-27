#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001];
int cnt[1001];
int previos[1001];
int ret =1;
int idx;
vector<int> b;

int main(){
	cin>>n;
		
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		int max_value = 0;
		for(int j=0; j<i; j++){
			if(a[j]<a[i]&& max_value<cnt[j]){			
				max_value = cnt[j];
				previos[i] = j;
				}
			}
		cnt[i] = max_value+1;
		if(cnt[i]>ret){
			ret = cnt[i];
			idx=i;
		}
	}
	
		
	cout<<ret<<"\n";
	for(int i=0; i<ret; i++){
		b.push_back(a[idx]);
		idx = previos[idx];
	}
	
	for(int i=ret-1; i>=0; i--){
		cout<< b[i]<<" ";
	}
	
	return 0;
}
