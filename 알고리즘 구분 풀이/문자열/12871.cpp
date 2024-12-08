#include<bits/stdc++.h>
using namespace std;
string s1;
string s2;
string rs1,rs2;
int cnt,cnt2;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // (a * b) / GCD(a, b)를 계산 (오버플로우 방지를 위해 a / GCD 사용)
}

int main(){
	cin>>s1>>s2;
	bool flag= true;
	for(int i=0; i<s1.size()-1; i++){
		if(s1[i]!= s1[i+1]){
			cnt=2;
			break;
		}
	}
	for(int i=0; i<s2.size()-1; i++){
		if(s2[i]!= s2[i+1]){
			cnt2=2;
			break;
		}
	}
	if(cnt==0&&cnt2==0&&s1[0]==s2[0]){
		cout<<1;
	}
	else{
		if(s1.size()>s2.size()){
		int minl = lcm(s1.size(),s2.size());
		int value = minl/s1.size();
		for(int i=0; i<value; i++){
			rs1+=s1;
		}
		int idx=0;
		while(true){
		if(rs1.size()==idx)break;
		string temp = rs1.substr(idx,s2.size());
		if(temp==s2) {
		}
		else{
			flag= false;
			break;
		}
		idx+=s2.size();
		}
	}
	else{
		int minl = lcm(s1.size(),s2.size());
	//	cout<<minl<<"\n";
		int value = minl/s2.size();
		for(int i=0; i<value; i++){
			rs2+=s2;
		}
		string temp = s2.substr(0,s1.size());
		int idx=0;
		while(true){
		if(rs2.size()==idx)break;
		string temp = rs2.substr(idx,s1.size());
		if(temp==s1) {
		}
		else{
			flag= false;
			break;
		}
		idx+=s1.size();
		}
	}
	if(flag) cout<<1;
	else cout<<0;
	}

	
	return 0;
}
