#include<bits/stdc++.h>
using namespace std;
const int INF =987654321;
int n;
int cnt=INF;

void go(deque<char> dq,int nn){
	if(nn>=2){
		return;
	}
	while(true){
		if(dq.size()<=1){
			cnt= min(cnt,nn);
			break;
		}
		if(dq.front()==dq.back()){
			dq.pop_front();
			dq.pop_back();
		}
		else{
			int b= dq.front();
			dq.pop_front();
			go(dq,nn+1);
			dq.push_front(b);
			dq.pop_back();
			go(dq,nn+1);
			break;
		}
	}
	return;
}


int main(){
	cin>>n;
	
	while(n--){
		cnt= INF;
		string s;
		cin>>s;
		deque<char> dq;
		for(int i=0; i<s.size(); i++){
			dq.push_front(s[i]);
		}
		go(dq,0);
		if(cnt==INF) cout<<2<<"\n";
		else
		cout<<cnt<<"\n";
	}
	
	return 0;
}
