#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
int cnt;

bool check(string temp,string temp2){
	map<char,char> mp;
	map<char,char> mp2;
	for(int i=0;i<temp.size(); i++){
			if(mp.find(temp[i])!= mp.end() && mp[temp[i]]!= temp2[i]){
			//	cout<<temp<<" "<<temp2<<"\n";
				return false;
			}
			else if(mp2.find(temp2[i])!= mp2.end() && mp2[temp2[i]]!= temp[i]){
				return false;
			}
			else{
				mp[temp[i]]= temp2[i];
				mp2[temp2[i]]= temp[i];
			}

	}
	//<<temp<<" "<<temp2<<"\n";
	return true;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	for(int i=0; i<n-1; i++){
		string temp = v[i];
		for(int j=i+1; j<n; j++){
			string temp2 = v[j];
			if(check(temp,temp2)){
				cnt++;	
			}
		}
	}
	cout<<cnt;
	
	return 0;
}
