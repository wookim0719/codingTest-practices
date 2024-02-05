#include<bits/stdc++.h>
using namespace std;
vector<int> alphabet(26);

int main(){
	string sent;
	cin>> sent;
	
	for(int i=0; i<sent.size(); i++){
		int a = (int)sent[i] -97;
		alphabet[a]++;
		}
		
	for(int i=0; i<26; i++){
		cout<< alphabet[i] << " ";
	}
	

}
