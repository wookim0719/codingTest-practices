#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_set<string> mp;
vector<string> voca;
//unordered_map의 경우에 검색에 대한 시간 복잡도는 1이고 map은 n을 가진다. 

void split(string s){
	int count=0;
	string temp="";
	for(int i=0; i<s.size(); i++){
		if(s[i]==','){
			voca.push_back(temp);
			temp="";
		}
		else{
			temp+=s[i];
		}
	}
	voca.push_back(temp);
	return ;
}

int main(){
ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n ;i++){
		string s;
		cin>>s;
		mp.insert(s);
	}
		int cnt=0;
	for(int i=0; i<m;i++){
		voca.clear();
		string s2;
		cin>>s2;
		split(s2);
		for(string v:voca){
			if(mp.count(v)){
				mp.erase(v);
				cnt++;	
			}
		}
		cout<<n-cnt<<"\n";	
	}
	return 0;
}
