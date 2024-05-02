#include<bits/stdc++.h>
using namespace std;
int n, c;
map<int,int> mp;
vector<int> a;

int main(){
	cin>>n>>c;
	for(int i=0;i<n; i++){
		int temp;
		cin>>temp;
		mp[temp]++;
		if(a.end()==find(a.begin(),a.end(),temp)){
			a.push_back(temp);	
		}
	}
	while(true){
		if(a.size()==0) break;
		int max_value=0;
		int index=0;
		for(int i:a){
			if(max_value<mp[i]) {
			max_value = mp[i];	
			index= i;
			}
		}
		for(int i=0; i<mp[index]; i++){
			cout<<index<<" ";
		}
		a.erase(find(a.begin(),a.end(),index));	
	}

	return 0;
}
