#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[201];
vector<int> v;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int ret=0;
	for(int i=0; i<n; i++){
		int maxv= 0;
		for(int j=0; j<i; j++){
			if(v[j]<v[i]&&maxv<cnt[j]) maxv=cnt[j];
		}
		cnt[i]= maxv+1;
		ret= max(cnt[i],ret);
	}
	
	cout<<n-ret;
	return 0;
}
