#include <bits/stdc++.h>
using namespace std;

int n,m;
map<string,int> v;
vector<string> v2[100001];

int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
		cin>>n>>m;

	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		 v[temp]++;
	}
	
	int max_value= 0;
	
	for(auto p: v){
		max_value = max(max_value,p.second);
		v2[p.second].push_back(p.first);
	}
	
	while(max_value>0){
		vector<string> temp2= v2[max_value];
		sort(temp2.begin(), temp2.end(), 
              [](const string& a, const string& b) {
                   if (a.length() != b.length()) {
                      return a.length() > b.length();
                  }
                  return a < b;
              });
		for(string i:temp2){
			if(i.size()>=m){
				cout<<i<<"\n";
			}
		}
		max_value--;
	}
	
	return 0;
}
