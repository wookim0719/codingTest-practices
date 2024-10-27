#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;
int ret;

bool check(string str, int idx){
	string temp = "";
	while(true){
		if(temp.size()==s.size()) break;
		temp+=str[idx];
		idx++;
		if(idx>=str.size()){
			idx= 0;
		}
	}
	
	if(temp==s) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s>>n;
	
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	for(int i=0; i<n; i++){
		string temp= v[i];
		for(int j=0; j<temp.size(); j++){
			if(check(temp,j))
			{
				ret++;
				break;
			}
		}
	}
	cout<<ret;
	return 0;
}
