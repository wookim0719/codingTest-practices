#include<bits/stdc++.h>
using namespace std;
string s;
int ret=0;
bool isplin(int nn){
	int e= s.size()-1;
	bool flag= true;	
	while(nn<=e){
		char c= s[nn];
		char ee= s[e];
		if(c!=ee){
		//	cout<<c<<" "<<ee<<"\n";
			flag= false;
			break;
		}
		nn++;
		e--;
	}
	return flag;
}

int main(){
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(isplin(i)){
			int value=s.size()-i;
			ret = max(ret,value);
		}
	}
//	cout<<ret;
	cout<<2*s.size()-ret;
	return 0;
}
