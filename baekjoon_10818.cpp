
#include<bits/stdc++.h>
using namespace std;
int pos = 0;
string token = "";

 vector<int> split(string sentence, string delimeter){
 	vector<int> array ;
 	while((pos = sentence.find(delimeter))!= string::npos){
 		token = sentence.substr(0,pos);
 		int	token_inverted = stoi(token);
 		array.push_back(token_inverted);
 		sentence.erase(0, pos+ delimeter.length());	
	 }
	 int last_token = stoi(sentence);
	 array.push_back(last_token);
	 
	 return array;
 }
 
int main(){
	int a;
	int min;
	int max;
	int input;
	int value;
	cin >>a;
	for(int i=0; i<a; i++){
		cin >>input;
		if(i==0){
			min = input;
			max = input;
		}
		if(input>max)
		max = input;
		if(input<min)
		min = input;
				
	}
			cout<< min<< " "<< max;

//	vector<int> splited;
//	vector<int> numbers;
//	getline(cin, input);
//	getline(cin, input);
//	splited = split(input," ");
//
//	auto max = max_element(splited.begin(), splited.end());
//	auto min = min_element(splited.begin(), splited.end());
//	cout<<*min<<" "<<*max;
	
	return 0;
	

}
