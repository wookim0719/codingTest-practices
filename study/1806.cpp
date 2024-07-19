#include<bits/stdc++.h>
using namespace std;
int n,s;
vector<int> v;

int main(){
	cin>>n>>s;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	int f=0;
	int sum=v[0];
	int e=0;
	int ret=987654321;
	
	while(true){
//		cout<<f<<" "<<e<<" "<<sum<<"\n";
	  if(sum<s){
	  	e+=1;
	  	if(e==n) break;
	  	sum+=v[e];
	  }
	  else if(sum>=s){
	  	ret = min(ret,e-f+1);
	  	sum-=v[f];
	  	f+=1;
	  	if(f==n) break;
	  }
	}
	if(ret!=987654321)
	cout<<ret;
	else cout<<0;
	return 0;
}
