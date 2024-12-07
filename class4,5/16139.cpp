#include<bits/stdc++.h>
using namespace std;
string s;
int q;
int alpha[30][200001];
vector<char> v ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	cin>>q;
	for(int i=0; i<26; i++){
		v.push_back('a'+i);
	}
	
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		if(i!=0)
		for(char k: v){
			alpha[k-'a'][i]= alpha[k-'a'][i-1];
		}
		if(i!=0)
		alpha[c-'a'][i] = alpha[c-'a'][i-1]+1;
		else{
			alpha[c-'a'][i]=1;
		}
	}
	
	while(q--){
		char c;
		int t1,t2;
		cin>>c>>t1>>t2;
		if(t1==0){
			cout<<alpha[c-'a'][t2]<<"\n";
		}
		else{
			cout<<alpha[c-'a'][t2]- alpha[c-'a'][t1-1]<<"\n";
		}
	}
	
	
	return 0;
}
