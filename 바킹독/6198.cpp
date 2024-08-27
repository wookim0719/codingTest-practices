#include<bits/stdc++.h>
using namespace std;
int n;
long long ret;

int main(){
	cin>>n;
	stack<pair<int,int>> stk;
	for(int i=0; i<n; i++){
		int h;
		cin>>h;
		while(stk.size()){
			auto t= stk.top();
			if(t.first<=h){
				stk.pop();
		//		cout<<i-t.second-1<<"\n";
				ret+= i-t.second-1;
			}
			else break;
		}
		stk.push({h,i});
	}
	while(stk.size()){
		auto t= stk.top();
		ret+= (n-1)-t.second;
	//	cout<<(n-1)-t.second<<"\n";
		stk.pop();
	}
	
	cout<<ret;
	
	return 0;
}
