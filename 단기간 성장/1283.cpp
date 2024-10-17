#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
map<char,int> mp;
vector<int> countt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cin.ignore();
	for(int i=0; i<n; i++){
		string s;
		getline(cin,s);
		v.push_back(s);
	}
	
	for(string ss: v){
		bool flag= false;
		bool flag2= false;
		queue<char> q;
		vector<pair<char,int>> ff;
		for(int j=0; j<ss.size(); j++){
			q.push(ss[j]);
			char c= ss[j];
			if(c==' '){
				flag= true;
				ff.push_back({ss[j+1],j+1});
			}
		}
		char ffirst = ss[0];
		if(mp[ffirst]==0){
			mp[ffirst] = 1;
				if(ffirst>=97){
					mp[ffirst-32]=1;
				}
				else mp[ffirst+32]=1;
			countt.push_back(0);
			flag2= true;
		}
		if(flag&&!flag2){
			for(auto c: ff){
				if(mp[c.first]==0){
					mp[c.first]=1;
					if(c.first>=97){
					mp[c.first-32]=1;
				}
				else mp[c.first+32]=1;
					flag2=true;
					countt.push_back(c.second);
					break;
				}
			}
		}
		if(!flag2){
		int cnt=0;
		while(q.size()){
			char f= q.front();
			q.pop();
			if(mp[f]==0&&f!=' '){
				mp[f]=1;
				if(f>=97){
					mp[f-32]=1;
				}
				else mp[f+32]=1;
				countt.push_back(cnt);
				flag2=true;
				break;
			} 
			cnt++;
		}
		}
		if(!flag2){
			countt.push_back(-1);
		}
	}
	
	for(int i=0; i<v.size(); i++){
		string tmp = v[i];
		int value = countt[i];
		queue<char> q;
		for(char s: tmp){
			q.push(s);
		}
		int ccnt=0;
		while(q.size()){
		//	cout<<ccnt;
			if(ccnt==value&&value!=-1){
				cout<<"[";
			}
			else if(ccnt== value+2&&value!=-1){
				cout<<"]";
			}
			else {
			cout<<q.front();
			q.pop();	
			}
			ccnt++;
		}
		if(value==tmp.size()-1) cout<<']';
		cout<<"\n";
	}
	
	return 0;
}
