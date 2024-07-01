#include<bits/stdc++.h>
using namespace std;
int n,d,k,c;
int ret;
int cnt;
vector<int> v;
map<int,int> mp;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>d>>k>>c;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	for(int i=0; i<k; i++){
		if(!mp[v[i]]) cnt++;
		mp[v[i]]++;
	}
	if(!mp[c]) cnt++;
	mp[c]++;
	ret= cnt;
	//cout<<ret;
	
	for(int i=1; i<n; i++){
		mp[v[i-1]]--;
		if(mp[v[i-1]]==0) {
		//cout<<"감소";
		cnt--; 
		}
		if(mp[v[((i+k-1)%n)]]==0) {
			cnt++;
	//		cout<<"증가";
		}
		mp[v[((i+k-1)%n)]]++;
		//cout<<v[i-1]<<" "<<v[((i+k-1)%n)]<<" "<<cnt<<"\n";
		ret= max(ret,cnt);
	}
	cout<<ret;
	return 0;
}
