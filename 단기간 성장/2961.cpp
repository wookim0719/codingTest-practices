#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int n;
int ret=987654321;

void go(int idx,int sum,int sum2){
	if(idx==n)return; 
	int temp = sum;
	int temp2 = sum2;
	ret= min(ret,abs(temp*v[idx].first-temp2-v[idx].second));
//	cout<<abs(temp*v[idx].first-temp2-v[idx].second)<<"\n";
	go(idx+1,temp*v[idx].first,temp2+v[idx].second);
	go(idx+1,sum,sum2);
	return;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int n1,n2;
		cin>>n1>>n2;
		v.push_back({n1,n2});
	}
	go(0,1,0);
	cout<<ret;
	return 0;
}
