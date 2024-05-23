#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[1001];
int a[1001];
int ret;

int main(){
	cin>>n;
	for(int i=0; i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		int max_cnt=0;
		for(int j=0; j<i; j++){
			if(a[j]<a[i]&&(cnt[i]+1)<=cnt[j]) max_cnt=max(max_cnt,cnt[j]);
		}
		max_cnt+=1;
		ret= max(ret,max_cnt);
		cnt[i]= max_cnt;
	}
	cout<<ret;
	
	return 0;
}
