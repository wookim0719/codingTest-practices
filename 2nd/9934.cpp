#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000];
int total;
vector<int> level[10];

void divide(int start, int end, int num){
	int center = (start+end)/2;
	if(end-start==2){
		level[num+1].push_back(a[start]);
		level[num+1].push_back(a[end]);
		level[num].push_back(a[center]);
		return;
	}
	level[num].push_back(a[center]);
	divide(start, center-1,num+1);
	divide(center+1, end, num+1);
	return;
}

int main(){
	cin>>n;
	total = pow(2,n)-1;
	for(int i=0; i<total; i++){
		cin>>a[i];
	}	
	if(n==1){
		cout<<a[0];
		return 0;
	}
	
	divide(0, total-1,0);
	
	for(int i=0; i<n; i++){
		for(int j:level[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
