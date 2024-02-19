#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int main(){
	cin>>n;
	int i =0;
	int value;
	while(true){
		string str = to_string(i);
		if(str.find("666")!= string::npos){
			cnt++;
			value =  i;
		}
		
		if(cnt == n) break;
		i++;
	}
	cout<< value;
	return 0;
}
