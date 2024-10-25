#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
	while(true){
	v.clear();
	vector<pair<string,int>> v2;
	v2.clear();
	int n;
	cin>>n;
	if(n==0) break;
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
		for(int j=0; j<temp.size(); j++){
			if(temp[j]<97){
				temp[j]+=32;
			}
		}
		v2.push_back({temp,i});
	}
	sort(v2.begin(),v2.end());
	
//	for(auto i: v2)cout<<i.first<<"\n";
	cout<<v[v2[0].second]<<"\n";	
	}

	return 0;
}
