#include<bits/stdc++.h>
using namespace std;
string s;

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(){
	cin>>s;
	int pos=0;
	int n=s.size();
	for(int i=0; i<n; i++){
		if(s[i]==':')
		pos= i;
	}

	string t1 = s.substr(0,pos);
	string t2 = s.substr(pos+1,n-pos);
	
	int i1= stoi(t1);
	int i2= stoi(t2);
	
	if(i1!=i2){
		int a = gcd(i1,i2);
		cout<<i1/a<<':'<<i2/a;	
	}
	else{
		cout<<"1:1";
	}
	return 0;
}
