#include<bits/stdc++.h>
using namespace std;
int n;
int ret=987654321;
vector<int> a;

void count(vector<int> v, int cnt){
	if(v[0]<=0&&v[1]<=0&&v[2]<=0) {
		ret = min(cnt,ret);
		return;
	}
	sort(v.begin(),v.end());
	vector<int> temp = {v[0]-1,v[1]-3,v[2]-9};
	count(temp,cnt+1);
	vector<int>temp2={v[0]-3,v[1]-1,v[2]-9};
	count(temp2,cnt+1);		
	return;
}


int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	
	for(int i=n; i<3; i++){
		a.push_back(0);
	}
	
	count(a,0);
	 
	cout<<ret;
	return 0;
} 
