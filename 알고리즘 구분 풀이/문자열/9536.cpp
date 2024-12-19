#include<bits/stdc++.h>
using namespace std;
int t;
map<string,int> mp;
string goal;

bool check(string temp){
	if(temp.find("goes")!= string::npos){
		auto idx= temp.find("goes");
		string word = temp.substr(idx+5,temp.size()-idx-4);
		mp[word]=1;
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		mp.clear();
		while(true){
			string temp;
			getline(cin,temp);
			if(temp=="what does the fox say?") break;
			else{
				if(!check(temp)){
					goal = temp;
				}
			}
		}
		int s=0;
		int e=0;
	//	cout<<goal<<"\n";
		for(int i=0; i<goal.size(); i++){
			if(goal[i]==' '){
				e= i-1;
				string temp = goal.substr(s,e-s+1);
			//	cout<<temp<<"\n";
				if(!mp[temp])
				cout<<temp<<" ";
				s=i+1;
			//	cout<<s<<" "<<e;
			}
		}
		string temp = goal.substr(s,goal.size());
		if(!mp[temp]) cout<<temp;
		cout<<"\n";
	}
	
	
	return 0;
}
