#include <bits/stdc++.h>
using namespace std;
int num;
double score;
double finalScore;
map<string,double> mp;
int main(){
	mp["A+"]= 4.5;
	mp["A0"] = 4.0;
	mp["B+"]= 3.5;
	mp["B0"] = 3.0;
	mp["C+"] = 2.5;
	mp["C0"] = 2.0;
	mp["D+"] = 1.5;
	mp["D0"]= 1.0;
	mp["F"]= 0.0;
	for(int i=0; i<20; i++){
		string s,s2,s3;
		cin>>s>>s2>>s3;
		int point = s2[0]-'0';
		if(s3[0]!='P'){
		num+=point;
		score+=mp[s3]*point;
		}
	//	cout<<score<<"\n";
	}
	if(num>0)
	finalScore = score/num;
//	cout<<num<<"\n";
	cout<<finalScore;
	return 0;
}
