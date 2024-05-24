#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		int temp=0;
		cin>>temp;
		if(temp==0){
			if(pq.size()){
			cout<<pq.top()<<"\n";
			pq.pop();
			}
			else cout<<0<<"\n";
		}
		else{
			pq.push(temp);	
		}
	}
	
	
	return 0;
}

