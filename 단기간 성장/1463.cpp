#include<bits/stdc++.h>
using namespace std;
int ret=987654321;

int main(){
	int n;
	cin>>n;
	queue<pair<int,int>> q;
	q.push({n,0});
	
	while(q.size()){
	 auto f= q.front();
	 q.pop();
	 if(f.first==1){
	 	ret= min(ret,f.second);
	 	break;
	 }
	 int num= f.first;
	 if(num%3==0){
	 	q.push({num/3,f.second+1});
	 }
	 if(num%2==0){
	 	q.push({num/2,f.second+1});
	 }
	 if(num-1>=1){
	 	q.push({num-1,f.second+1});
	 }
	}
	
	cout<<ret;
	
	
	return 0;
}
