#include<bits/stdc++.h>
using namespace std;
string s;
int n;
vector<string> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	int n = s.size();
	for(int i=1; i<=n-2; i++){
		for(int j=1; j<=n-1-i; j++){
			string t1= s.substr(0,i);
			string t2= s.substr(i,j);
			string t3= s.substr(i+j,n-i-j);
			reverse(t1.begin(),t1.end());
			reverse(t2.begin(),t2.end());
			reverse(t3.begin(),t3.end());
			string ss= t1+t2+t3;
			v.push_back(ss);
		}
	}
	
	sort(v.begin(),v.end());	
	
	cout<<v[0];
	return 0;
}
