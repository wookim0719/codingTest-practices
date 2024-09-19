#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> t1;
int n;
priority_queue<t1,vector<t1>,greater<t1>> pq;
int main(){
	cin>>n;
	int cnt=0;
	while(true){
		if(n==cnt) break;
		int temp;
		cin>>temp;
		if(temp!=0){
			if(temp>0)
			pq.push({temp,1});
			else
			pq.push({temp*-1,0});
		}
		else{
			if(pq.size()){
				if(pq.top().second==0)
				cout<<pq.top().first*-1<<"\n";
				else
				cout<<pq.top().first<<"\n";
				pq.pop();
			}
			else
			cout<<0<<"\n";
		}
		cnt++;
	}
	
}
