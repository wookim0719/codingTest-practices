#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
vector<int> v2;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	cin>>m;
	for(int i=0; i<m; i++){
		int temp;
		cin>>temp;
		v2.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0; i<m; i++){
		int goal = v2[i];
		int s=0;
		int e=v.size()-1;
		bool flag=false;
		while(s<=e){
			int mid= (s+e)/2;
			if(goal>v[mid]){
				s=mid+1;
			}
			else if(goal==v[mid]){
				flag= true;
				break;
			}
			else{
				e=mid-1;
			}
		}
		if(flag) cout<<1<<" ";
		else cout<<0<<" ";
	}
	
	
	return 0;
}
