#include<bits/stdc++.h>
using namespace std;
string s,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>s>>s2){
	size_t pos= 0;
	bool flag=true;
	for(int i=0; i<s.size(); i++){
		pos = s2.find(s[i],pos);
		if(pos!=string::npos){
			pos+=1;
		}
		else{
			flag = false;
					break;
		}
	}
		if(flag) cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}

	return 0;
}
