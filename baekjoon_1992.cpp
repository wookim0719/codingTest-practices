#include <bits/stdc++.h>
using namespace std;

int n;
const int max_n= 101;
int a[max_n][max_n];
string s;

string compress(int y, int x, int size){
	string ret = "";
	if(size ==1) return string(1, a[y][x]);
	char b= a[y][x];
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(b!= a[i][j]){
				ret += '(';
				ret += compress(y, x, size / 2); 
                ret += compress(y, x + size / 2, size / 2);
                ret += compress(y + size / 2, x, size / 2);
                ret += compress(y + size / 2, x + size / 2, size / 2); 
                ret += ')';
                return ret;
			}
		}
	}
	return string(1, a[y][x]);
}

int main(){
  cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
	}
	
	
	cout<< compress(0,0,n)<< "\n";
	
	return 0;
}
