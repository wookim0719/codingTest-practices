#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> v;
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
		mp[temp]++;
	}
	
	for(int i=0; i<n; i++){
		int now = v[i];
		int cnt=0;
		set<int> st;
		for(int j=1; j*j<=now; j++){
			if(now%j==0){
				if(j!=now)
				st.insert(j);
				if((now/j)!=now)
				st.insert(now/j);
			}
		}
		for(int i: st){
			cnt+=mp[i];
		}
		cnt+=(mp[now]-1);
		cout<<cnt<<"\n";		
	}
	
	return 0;
}
