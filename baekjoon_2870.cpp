#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> arr;

bool cmp(string a, string b){
	if(a.size() == b.size()) return a<b;
	return a.size() <b.size();
}

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		string temp;
		cin>> temp;
		string can ="";
		for(int j=0; j<temp.size(); j++){
			char word = temp[j];
			if(isdigit(word)){
				can = can+to_string(word-48);
				if(j==temp.size()-1||temp[j+1]>58){
				while(true){
					if(can.size()&&can.front() == '0') can.erase(can.begin());
					else break;
				}
				if(can.size()==0) can = "0";
				arr.push_back(can);
			}
			}
			else{
				can = "";
			}
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	for(string a: arr){
		cout<< a<<"\n";
	}
	
	return 0;
}
