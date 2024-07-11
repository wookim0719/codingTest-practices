#include <bits/stdc++.h>
using namespace std;
int n;
string s, g;
int ret=987654321;


void go(string temp, int p, int cnt){
	
	for(int i=p; i<temp.size(); i++){
		//	cout<<temp<<"\n";
		if(i!=temp.size()-1){
		if(temp[i-1]!= g[i-1]){
			temp[i-1]= (temp[i-1]=='0')?'1':'0';
			temp[i]= (temp[i]=='0')?'1':'0';
			temp[i+1]= (temp[i+1]=='0')?'1':'0';
			cnt++;
		}
	}
	else{
	if(temp[i-1]!= g[i-1]){
			temp[i-1]= (temp[i-1]=='0')?'1':'0';
			temp[i]= (temp[i]=='0')?'1':'0';
			cnt++;
		}	
	}
	}
	if(temp==g)
	ret= min(ret,cnt);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    cin >> s >> g;
    
    go(s,1,0);
    if(s[0]=='1')s[0]='0';
    else s[0]='1';
  	if(s[1]=='1')s[1]='0';
    else s[1]='1';
	//cout<<s<<"\n";   
	go(s,1,1);
	if(ret==987654321) ret=-1;
    cout<<ret;
    return 0;
}

