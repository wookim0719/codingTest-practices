#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
map<int,int> mp;

int main(){
	cin>>n;
	cin.ignore();
	for(int i=0; i<n; i++){
		string temp;
		getline(cin,temp);
		v.push_back(temp);
	}	
	for(int i=0; i<n; i++){
		mp.clear();
		int min_v =987654321;
		string now = v[i];
		for(char c: now){
			if((c-'a')>=0&& (c-'a')<=25){
				mp[c-'a']++;
			}
			if((c-'A')>=0&& (c-'A')<=25){
				mp[c-'A']++;
			}
		}
		
		for(int j=0; j<=25; j++){
			min_v = min(min_v,mp[j]);
		}
		cout<<"Case "<<i+1<<": ";
		if(min_v==1) {
			cout<<"Pangram!"<<"\n";
		}
		else if(min_v==2){
			cout<<"Double pangram!!"<<"\n";
		}
		else if(min_v >=3){
			cout<<"Triple pangram!!!"<<"\n";
		}
		else{
			cout<<"Not a pangram"<<"\n";
		}
	}
	return 0;
}
