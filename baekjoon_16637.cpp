#include <bits/stdc++.h>
using namespace std;
int n;
string input;
char a[20];
string collect[100];
string b;
vector<int> num;
vector<char> oper_;
int ret = -987654321;

int oper(char a, int b, int c) {
	if(a== '+') return b+c;
	if(a == '-') return b - c; 
    if(a == '*') return b * c; 
}

void go(int here, int _num){
	if(here == num.size() -1){
		ret =  max(ret, _num);
		return;
	}
	go(here+1,oper(oper_[here], _num, num[here+1]));
	
	if(here +2<= num.size() -1){
		int temp = oper(oper_[here+1], num[here+1],num[here+2]);
		go(here+2,oper(oper_[here],_num,temp));
	}
	return;
}

int main(){
	cin>> n;
	cin>> input;
	for(int i=0; i<input.size(); i++){
		if(i%2==0) num.push_back(input[i]- '0');
		if(i%2==1) oper_.push_back(input[i]);
	}
	
	go(0, num[0]);
	cout<<ret<<"\n";
	return 0;
}
