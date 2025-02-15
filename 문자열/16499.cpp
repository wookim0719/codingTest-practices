#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
map<string,int> mp;
int ret;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		sort(temp.begin(),temp.end());
		if(!mp[temp]){
			ret++;
			mp[temp]++;
		}	
	}
	cout<<ret;
	return 0;
}
