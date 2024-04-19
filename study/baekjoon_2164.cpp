#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> dq;

int main(){
	cin>>n;
	
	for(int i=1; i<=n; i++){
		dq.push_back(i);
	}
	
	while(dq.size()!=1){
		dq.pop_front();
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}
	
	int res = dq.front();
	
	cout<<res;
	
	return 0;
}
