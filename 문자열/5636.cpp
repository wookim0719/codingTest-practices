#include<bits/stdc++.h>
using namespace std;
int ret=0;

bool isprime(int n){
	// 1보다 작거나 같은 수는 소수가 아님
    if (n <= 1) return false;
    // 2와 3은 소수
    if (n <= 3) return true;
    // 짝수와 3의 배수는 소수가 아님
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 5부터 √n까지 홀수로 나누어 보며 소수 판별
    for (int i = 5; i <= std::sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void check(string s){
	for(int i=0; i<s.size(); i++){
		string str="";
		int idx= i;
		while(true){
			if(idx==s.size()|| str.size()==6) break;
			str+=s[idx];
			if(isprime(stoi(str))){
				int value= stoi(str);
				if(value<=100000)
				ret = max(ret,value);
			}
			idx++;
		}
	}
	return;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true){
		ret =0;
		string s;
		cin>>s;
		if(s=="0") break;
		check(s);
		cout<<ret<<"\n";
	}
	return 0;
}
