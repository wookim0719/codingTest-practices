
#include <bits/stdc++.h>
using namespace std;
int main(){
	string word;
	cin>> word;
	bool output = true;
	int repeat = word.size() / 2;	
	for(int i=0; i<repeat; i++){
		if(word[i] != word[word.size()-i-1])
			output= false;
	}	
	
	cout<<output;
	
	return 0;
	
}
