#include<bits/stdc++.h>
using namespace std;
vector<int> t[4];
int k;
int ret;
vector<int> lv;
vector<int> rv;

void left_check(int n){
	while(true){
	  if(n==0) break;
	  if(t[n][6]!=t[n-1][2]){
	  	lv.push_back(n-1);
	  	 n--;
	  }
	  else break;
	}
	return;
}

void right_check(int n){
	while(true){
	  if(n==3) break;
	  if(t[n][2]!=t[n+1][6]){
	  	rv.push_back(n+1);
	  	n++;
	  }
	  else break;
	}
	return;
}

void rot(int n, int d){
	lv.clear();
	rv.clear();
	left_check(n);
	right_check(n);
	int ld=d;
	int rd=d;
	for(int i=0; i<lv.size(); i++){
		if(ld==1){
		ld=-1;	
		rotate(t[lv[i]].begin(),t[lv[i]].begin()+1,t[lv[i]].end());
		}
		else{
		rotate(t[lv[i]].rbegin(),t[lv[i]].rbegin()+1,t[lv[i]].rend());
		ld=1;	
		}
	}
	for(int i=0; i<rv.size(); i++){
		if(rd==1){
		rd=-1;	
		rotate(t[rv[i]].begin(),t[rv[i]].begin()+1,t[rv[i]].end());
		}
		else{
		rotate(t[rv[i]].rbegin(),t[rv[i]].rbegin()+1,t[rv[i]].rend());
		rd=1;	
		}	
	}
	return;
}

int main(){
	for(int i=0; i<4; i++){
		string s;
		cin>>s;
		for(int j=0; j<8; j++){
			t[i].push_back(s[j]-'0');
		}	
	}
	cin>>k;
	while(true){
		if(k==0)break;
		int a,b;
		cin>>a>>b;
		rot(a-1,b);
		if(b==1)
		rotate(t[a-1].rbegin(),t[a-1].rbegin()+1,t[a-1].rend());
		else{
		rotate(t[a-1].begin(),t[a-1].begin()+1,t[a-1].end());
		}
		k--;
	}			
	if(t[0][0]==1) ret+=1;
	if(t[1][0]==1) ret+=2; 
	if(t[2][0]==1) ret+=4; 
	if(t[3][0]==1) ret+=8; 
	
	cout<<ret;
	
	return 0;
}

