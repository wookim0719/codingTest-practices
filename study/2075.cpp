#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int, std::vector<int>, std::greater<int>> pq;
int ret;

int main(){
	ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int temp;
			cin>>temp;
			pq.push(temp);
			if(pq.size()>n) pq.pop();
		}
	}
	
	ret= pq.top();
	cout<<ret;
	return 0;
}
