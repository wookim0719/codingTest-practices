#include<bits/stdc++.h>
using namespace std;
int n;
int ret;
queue<pair<int,int>> q;
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n; i++){
		int temp,temp2;
		cin>>temp>>temp2;
		q.push({temp,temp2});
	}
	int prev1=0;
	int nowh=q.front().second;
	
	while(q.size()){
		nowh=q.front().second;
//		cout<<prev1<<nowh;
	//	cout<<nowh;
		q.pop();
		if(nowh<prev1){
			if(nowh==0){
				if(v.size()&&v[v.size()-1]!=prev1&&prev1!=0)
				v.push_back(prev1);
				else if(!v.size()&&prev1!=0)v.push_back(prev1);
				int temp;
				if(v.size()) {
				temp=v[0];
				ret++;	
				}
				for(int i=0; i<v.size(); i++){
					temp=min(temp,v[i]);
				}
				for(int i=0; i<v.size(); i++){
				if(v[i]!=temp) ret++;	
				}
				v.clear();
			}
			else{
				ret++;
				if(v.size()&&v[v.size()-1]==prev1) v.pop_back();
			}
		}
		else if(nowh>prev1){
		if(!v.size()){
			if(prev1!=0)
		v.push_back(prev1);	
		} 
		else if(v.size()&&prev1!=v[v.size()-1]&&prev1!=0){
		  v.push_back(prev1);
	}
		}

		prev1=nowh;
//	cout<<"\n";
//		cout<<v.size();
//	for(int k: v)cout<<k<<" ";
//		cout<<ret<<"\n";
	}
	if(v.size()&&v[v.size()-1]!=prev1&&prev1!=0)
		v.push_back(prev1);
	else if(!v.size()&&prev1!=0)v.push_back(prev1);
		int temp2;
	if(v.size()) {
		temp2=v[0];
		ret++;
	}
				for(int i=0; i<v.size(); i++){
					temp2=min(temp2,v[i]);
				}
				for(int i=0; i<v.size(); i++){
				if(v[i]!=temp2) ret++;	
				}
	//if(nowh!=0) ret++;
	cout<<ret;
	return 0;
}
