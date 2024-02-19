#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> arr;

int main(){
	cin>> n;
	for(int i=0; i<n; i++){
		string temp;
		stack<char> stk;
		cin>>temp;
		for(int j=0; j<temp.size(); j++){
		if(temp[j] == ')'){
			if(!stk.empty())
			stk.pop();
			else{
						stk.push(temp[j]);

			break;
	} 
}
		else{
			stk.push(temp[j]);
		}
		}
		if(!stk.empty()){
			arr.push_back("NO");
		}
		else
		arr.push_back("YES");		
	}
	
	for(auto i: arr){
		cout<<i<<"\n";
	}
	
	return 0;
}
