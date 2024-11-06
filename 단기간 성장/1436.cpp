#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int s=0;
	int cnt=0;
	while(true){
		string tmp = to_string(s);
		if(tmp.find("666") != string::npos){
			cnt++;
		if(cnt==n) {
			cout<<s;
			break;
		}
		}
		s++;
	}	
	
	return 0;
}
