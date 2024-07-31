#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> hp[51];
vector<int> ph[51];
queue<int> q;
int pos[51];
int visited[51];
int ret;

int main(){
	cin>>n>>m;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){
		int temp1;
		cin>>temp1;
		q.push(temp1);
	}
	int pn=0;
	int mm=m;
	while(mm--){
		int temp2;
		cin>>temp2;		
		for(int i=0; i<temp2; i++){
			int temp3;
			cin>>temp3;
			ph[pn].push_back(temp3);
			hp[temp3].push_back(pn);
		}
		pn++;
	}
	
	while(q.size()){
		int person= q.front();
		visited[person]=1;
		q.pop();
		for(auto j: hp[person]){
		if(pos[j]==0){
		ret++;
		pos[j]=-1;
		for(auto k: ph[j]){
		if(!visited[k])
		q.push(k);	
		}
		}			
		}
	}
	
	cout<<m-ret;
	
	return 0;
}
