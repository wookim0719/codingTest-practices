#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> st;
vector<int> v;
int a[9];
int cnt;

void go(int k, int nn){
	if(nn==m){
		for(int i=0; i<cnt; i++){
			for(int j=0; j<a[i]; j++){
				cout<<v[i]<<" ";
			}
		}
		cout<<"\n";
		return;
	}
	for(int i=k; i<cnt; i++){
		a[i]++;
		go(i,nn+1);
		a[i]--;
	}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		st.insert(temp);	
	}
	for(int i:st){
		v.push_back(i);
	}
	cnt= st.size();
	
	go(0,0);
	
	
	
	return 0;
}
