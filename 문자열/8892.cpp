#include<bits/stdc++.h>
using namespace std;

bool isR(string temp){
	deque<char> dq;
			for(int i=0; i<temp.size(); i++){
				dq.push_front(temp[i]);
			}
			while(true){
				if(dq.size()==1||dq.size()==0) break;
				if(dq.front()==dq.back()){
					dq.pop_front();
					dq.pop_back();
				}
				else break;
			}
			if(dq.size()==1||dq.size()==0){
				return true;
			}
			else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string ret = "";
		vector<string> v;
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			v.push_back(temp);
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(isR(v[i]+v[j])) {
					ret = v[i]+v[j];
					break;
				}
				if(isR(v[j]+v[i])) {
					ret = v[j]+v[i];
					break;
				}
			}
		}
		if(ret.size())
		cout<<ret<<"\n";
		else cout<<"0"<<"\n";
	}	
	
	return 0;
}
