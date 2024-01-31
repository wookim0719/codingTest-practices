#include<bits/stdc++.h>
using namespace std;

	string s;
	string token = "";
	int pos = 0;


 vector<string> split(string sentence, string delimeter){
 	vector<string> array ;
 	while((pos = sentence.find(delimeter))!= string::npos){
 		// 찾아준 부분까지 찾아서 잘라준다. 
 		token = sentence.substr(0,pos);
 		array.push_back(token);
 		sentence.erase(0, pos+ delimeter.length());	
	 }
	 array.push_back(sentence);
	 
	 return array;
 }
int main(){
// split을 실행할 문자열을 받아온다. 
	getline(cin, s);
	vector<string> arr = split(s," ");
	for(string a : arr){
		cout << a << '\n';
	}
	return 0;
	}
