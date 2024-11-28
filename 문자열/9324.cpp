#include<bits/stdc++.h>
using namespace std;
int n;
string temp;

bool check(string temp){
	map<char,int> mp;
	for(int i=0; i<temp.size(); i++){
		char now = temp[i];
	//	cout<<i<<"\n";
		if(mp[now]==2){
			if((i+1)<temp.size()&&temp[i+1]==now){
			mp[now]=0;
			i+=1;	
			}
			else {
		//	cout<<i;
			return false;	
			}
		}
		else{
			mp[now]++;
		}
//	cout<<temp[i]<<" "<<mp[temp[i]]<<"\n";
	}
	return true;
}

int main(){
	cin>>n;
	while(n--){
		cin>>temp;
		if(check(temp)) cout<<"OK"<<"\n";
		else cout<<"FAKE"<<"\n";
	}
	
	return 0;
}
