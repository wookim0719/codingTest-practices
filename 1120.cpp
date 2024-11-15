#include<bits/stdc++.h>
using namespace std;
string a,b;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	int cnt = 987654321;
	for(int i=0; i<=b.size()-a.size(); i++){
		int cntt=0;
		for(int j=0; j<a.size(); j++){
			if(a[j]!= b[i+j]){
				cntt++;
			}
		}
		cnt = min(cnt,cntt);
	}	
	cout<<cnt;
	return 0;
}
