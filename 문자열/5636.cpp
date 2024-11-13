#include<bits/stdc++.h>
using namespace std;
int ret=0;

bool isprime(int n){
	// 1���� �۰ų� ���� ���� �Ҽ��� �ƴ�
    if (n <= 1) return false;
    // 2�� 3�� �Ҽ�
    if (n <= 3) return true;
    // ¦���� 3�� ����� �Ҽ��� �ƴ�
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 5���� ��n���� Ȧ���� ������ ���� �Ҽ� �Ǻ�
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
