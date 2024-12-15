#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a,b,c,d;
int v[4];
int ret;

bool check(){
	if(v[0]>=b&&v[1]>=d&&v[2]>=a&&v[3]>=c)
	return true;
	else return false;
}

int main(){
	cin>>n>>m;
	cin>>s;
	cin>>a>>b>>c>>d;
	
	for(int i=0; i<m; i++){
		if(s[i]=='C'){
			v[0]++;
		}
		if(s[i]=='T'){
			v[1]++;
		}if(s[i]=='A'){
			v[2]++;
		}if(s[i]=='G'){
			v[3]++;
		}
	}
	if(check()) ret++;
	for(int i=m; i<n; i++){
		if(s[i-m]=='C'){
			v[0]--;
		}
		if(s[i-m]=='T'){
			v[1]--;
		}if(s[i-m]=='A'){
			v[2]--;
		}if(s[i-m]=='G'){
			v[3]--;
		}
		if(s[i]=='C'){
			v[0]++;
		}
		if(s[i]=='T'){
			v[1]++;
		}if(s[i]=='A'){
			v[2]++;
		}if(s[i]=='G'){
			v[3]++;
		}
		if(check())ret++;
	}
	cout<<ret;
	
	return 0;
}
