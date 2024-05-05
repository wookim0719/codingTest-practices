#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int v[1000001];
stack<int> st;
int main(){
	cin>>n;
	memset(v,-1,sizeof(v));
	for(int i=0;i<n; i++){
		cin>>a[i];
		while(st.size()&& a[st.top()]<a[i]){
			v[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}	
	
	return 0;
}
