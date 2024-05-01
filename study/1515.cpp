#include<bits/stdc++.h>
using namespace std;
string s;
int n=1;

int main(){
	cin>>s;
	while(true){
		for(int i=n; i<=n; i++){
			string temp = to_string(i);
			for(int j=0; j<temp.size(); j++){
				if(temp[j]==s[0]){
					s = s.substr(1);
				}
			}
		}
		if(s.size()==0) break;
		else
		n++;		
	}
	
	cout<<n;
	
	return 0;
}
