#include<bits/stdc++.h>
using namespace std;
int n;
int ret;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	
	while(pq.size()!=1){
		int f= pq.top();
		pq.pop();
		int s= pq.top();
		pq.pop();
		int sum =f+s;
		ret+=sum;
		pq.push(sum);
	}
//	ret+=pq.top();
	cout<<ret;
	
	return 0;
}
