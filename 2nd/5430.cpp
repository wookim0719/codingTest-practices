#include<bits/stdc++.h>
using namespace std;
int t;
string s,arr;
deque<int> a;
int n;

void calculate(){
	int cntd=0;
	bool cntR=false;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='R'){
			cntR= !cntR;
		}
		else if(s[i]=='D'){
			cntd++;
			if(a.size()==0) {
				cout<<"error";
				return;
			}
			else{
				if(!cntR)a.pop_front();
				else a.pop_back();
			}
		} 
	}
	if(cntR) reverse(a.begin(),a.end());
	cout<<'[';
	for(int i=0; i<n-cntd;i++){
		cout<<a[i];
		if(i!=n-1-cntd) cout<<",";
	}
	cout<<"]";
	return;
}

int main(){
	cin>>t;
	while(t--){
		a.clear();
		cin>>s>>n>>arr;
		int num=0;
		for(int i=0; i<arr.size(); i++){
			if(arr[i]!='['&&arr[i]!=']'&&arr[i]!=','){
				num= 10*num+(arr[i]-'0');
			}
			else if(arr[i]==','){
				a.push_back(num);
				num=0;
			}
		}
		if(num!=0)
		a.push_back(num);
		calculate();
	
		cout<<"\n";	
	}
	
	return 0;
}
