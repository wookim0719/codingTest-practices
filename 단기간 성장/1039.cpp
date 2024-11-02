#include<bits/stdc++.h>
using namespace std;
string n;
int k;
vector<char> v;
vector<char> v2;
vector<char> ans;
map<char,int> mp;
bool issame=false;
string ret="";

void go(int nn){
	//cout<<nn;
	if(nn==0){
		string ts="";
		for(char i: v){
			ts+=i;
		}
		ret= max(ret,ts);
		return;
	}	
	bool flag=true;
	for(int i=0; i<v.size(); i++){
		char now=  v[i];
		char temp = v[i];
		vector<int> cc;
		for(int j=i+1; j<v.size(); j++){
			if(now<v[j]&&temp<=v[j]){
				if(temp == v[j]){
					//cout<<j<<"\n";
					cc.push_back(j);
				}
				else{
					temp = v[j];
					cc.clear();
					cc.push_back(j);	
				}
			}
		}
			if(cc.size()){
				flag= false;
				for(int h=0; h<cc.size(); h++){
					//cout<<cc.size();
					//cout<<v[i]<<" "<<cc[h]<<"\n";
					char temp3= v[i];
					v[i] = v[cc[h]];
					v[cc[h]] = temp3;
					go(nn-1);
					v[cc[h]] = v[i];
					v[i] = temp3;
				}
				break;
			}
		}
		if(flag){
			if(!issame){
			char temp = v[v.size()-1];
			v[v.size()-1] = v[v.size()-2];
			v[v.size()-2] = temp;
			go(nn-1);
			v[v.size()-2] = v[v.size()-1];
			v[v.size()-1] = temp;	
			}	
			else{
				go(nn-1);
			}
		}
		return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	bool iszero= false;
	for(int i=0; i<n.size(); i++){
		if(n[i]=='0')iszero = true;
		v.push_back(n[i]);	
		mp[n[i]]++;
		if(mp[n[i]]>1) issame=true;
	}
	ans = v;
	sort(ans.begin(),ans.end(),greater<char>());
	if((v.size()==1)||(v.size()==2&&iszero)){
		cout<<-1;
	}
	else{
		go(k);
		cout<<ret;
	}	
	return 0;
}
