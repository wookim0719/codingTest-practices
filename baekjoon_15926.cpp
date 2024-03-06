#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int d[200001];
int max_value;
int cnt;

int main(){
	cin>>n>>s;
	stack<int> a;
	int num;
	for(int i=0; i<n; i++){
		if(s[i]=='('){
				a.push(i);					
		}
		if(s[i]==')'){
			if(!a.empty()){
				d[i] = d[a.top()] =1;
				a.pop();
			}		
		}
	
	}
	
	for(int i=0; i<n; i++){
		if(d[i]){
			cnt ++;
			max_value = max(max_value, cnt);		
		}
		else cnt = 0;
	}
	
	cout<<max_value;
	
	return 0;
}
