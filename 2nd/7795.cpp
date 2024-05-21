#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
vector<int> a;
vector<int> b;
int temp;
int cnt=0;


int main(){
	cin>>t;
	while(t--){
	cnt=0;
	a.clear();
	b.clear();
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0; i<m; i++){
		cin>>temp;
		b.push_back(temp);
	}
	sort(b.begin(),b.end());
	for(int i:a){ 
	int lo=0;
	int end= b.size()-1;
	int mid=0;
	while(lo<end){
		mid=(lo+end)/2;
		if(i<=b[mid]){
			end=mid-1;	
		}
		else if(i>b[mid]){
			lo=mid+1;
		}
	}
	if(i>b[end])cnt++;
	//cout<<lo<<" "<<end<<"\n";
	cnt+=end;
	}
	cout<<cnt<<"\n";

	}
	
	return 0;
}
