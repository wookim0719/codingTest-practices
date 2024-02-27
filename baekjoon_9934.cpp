#include <bits/stdc++.h>
using namespace std; 
int n;
int a[1024];
//각 레벨의 값들을 저장할 벡터  
vector<int> ret[14];

void go(int s, int e, int level){
	if(s>e) return;
	if(s == e){
		ret[level].push_back(a[s]);
		return;
	}
	int mid = (s+e) /2;
	ret[level].push_back(a[mid]);
	go(s,mid-1,level+1);
	go(mid+1,e,level+1);
	return; 
} 

int main(){
	cin>>n;
	// 2^n-1만큼의 노드를 가지고 있으므로  
	int _end = (int)pow(2,n) -1;
	for(int i=0; i<_end; i++){
		cin>> a[i];
	}
	go(0,_end,1);
	
	for(int i=1; i<=n; i++){
		for(int it: ret[i]){
			cout<< it<< " ";
		}
		cout<<"\n";
	}
	
	
	return  0;
}
