#include<bits/stdc++.h>
using namespace std;
map<string,double> mp;
double total;

int main(){
	string temp;
	while(getline(cin,temp)){
		total++;
		mp[temp]++;
	}
	
	for(auto& p: mp){
		cout<<p.first<<" ";
		double result= round((p.second/total)*1000000)/10000;
		cout<<fixed<<setprecision(4)<<result<<"\n";
	}
	return 0;
}
