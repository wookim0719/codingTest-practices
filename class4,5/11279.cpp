#include<bits/stdc++.h>
using namespace std;
int x;
priority_queue<int,vector<int>> pq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		if(temp==0){
			if(pq.size()){
				cout<<pq.top()<<"\n";
				pq.pop();
			}
			else cout<<0<<"\n";
		}
		pq.push(temp);
	}
	
	
	return 0;
}
