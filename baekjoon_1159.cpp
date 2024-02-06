#include <bits/stdc++.h>
using namespace std;

int main(){
	int hnumber;
	cin >> hnumber;
	map<char, int> mp;
	string name;
	vector<char> namearr;
	
	for(int i=0; i<hnumber; i++){
		cin>> name;
		char tmp = name[0];
		if(mp.find(name[0]) == mp.end()){
			mp.insert(make_pair(name[0], 1));
		}
		else{
			mp[name[0]]++;
		}
	}
	
	 for(auto i:mp){
	 	if(i.second>4){
	 		namearr.push_back(i.first);
		 }
	 }
	 
	 if(namearr.empty())
	 	cout<< "PREDAJA";
	else{
		sort(begin(namearr), end(namearr));
		for(char i: namearr){
			cout<< i;
		}
	}
	return 0;	
}
