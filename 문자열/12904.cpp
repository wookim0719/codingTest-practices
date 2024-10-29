#include<bits/stdc++.h>
using namespace std;
string s;
string goal;
bool flag= false;

void go(string middle){
	//cout<<middle<<"\n";
	if(middle==s){
		flag= true;
		return;
	}
	if(middle.size()==0) return;
	if(middle[middle.size()-1]=='A'){
		string middle2="";
		for(int i=0; i<middle.size()-1; i++){
			middle2+=middle[i];
		}
		go(middle2);
	}
	
	if(middle[middle.size()-1]=='B'){
		string middle3= "";
		if(middle.size()>=2){
			for(int i=middle.size()-2; i>=0; i--){
			middle3+=middle[i];
		}	
		}
		go(middle3);
	}
	
	return;
}

int main(){
	cin>>s;
	cin>>goal;
	go(goal);	
	if(flag)
	cout<<1;
	else cout<<0;
	return 0;
}
