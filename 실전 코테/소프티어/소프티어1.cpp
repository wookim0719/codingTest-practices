#include <iostream>
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> pocket;
queue<int> q;
queue<int> q2;
vector<int> v;
vector<int> temp;
int main() {
	int temp;
	while(cin>>temp){
		v.push_back(temp);
	}
	for(int i=0; i<v.size(); i++){
		if(q.size()<3){
			q.push(v[i]);
			mp[v[i]]=1;
		}
		else{
			if(mp[v[i]]==1){
				while(q2.size()) q2.pop();
				while(q.size()){
					int value = q.front();
					q.pop();
					if(value!=v[i]){
						q2.push(value);
					}
				}
				q2.push(v[i]);		
				q=q2;
			}
			else{
				int value = q.front();
				q.pop();
				cout<<value<<" ";
				mp[value] =0;
				mp[v[i]]=1;
				q.push(v[i]);
			}
		}
	}
	
	return 0;
}
