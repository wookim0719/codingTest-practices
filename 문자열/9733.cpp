#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
vector<string> v;
int main(){
	string temp;
	while(cin>>temp){
		mp[temp]++;
		n++;
	}
	v.push_back("Re");
	v.push_back("Pt");
	v.push_back("Cc");
	v.push_back("Ea");
	v.push_back("Tb");
	v.push_back("Cm");
	v.push_back("Ex");
	cout<<fixed<<setprecision(2);
	for(string s: v){
		double dd = (double)mp[s]/n;
		cout<<s<<" "<<mp[s]<<" "<< dd<<"\n";
	}
	
	cout<<"Total"<<" "<<n<<" "<<"1.00";
	
	return 0;
}
