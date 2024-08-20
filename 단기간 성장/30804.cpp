#include<bits/stdc++.h>
using namespace std;
int ret;
map<int,int> mp;
vector<int> v;

int main(){
	int n;
	cin>>n;
	for(int i=0 ;i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int left= 0;
	int right=0;
	while(right<n){
		mp[v[right]]++;
		
		while(mp.size()>2){
			mp[v[left]]--;
			if(mp[v[left]]==0) mp.erase(v[left]);
			left++;				
		}
		ret= max(ret,right-left+1);
		right++;
	}
	cout<<ret;
	return 0;
}
