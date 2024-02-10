#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int total;
	
	for(int i=0; i<n; i++){
		string temp;
		cin >>temp;
		stack<char> stk;
		for(int j=0; j<temp.size(); j++){
		if(stk.size()&&stk.top() == temp[j]) stk.pop();
		else{
			stk.push(temp[j]);
		}
	}
	if(stk.size() == 0) total++;
	}
	
	cout<<total;
	return 0;
}
