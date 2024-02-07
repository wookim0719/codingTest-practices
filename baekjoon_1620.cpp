#include <bits/stdc++.h>
using namespace std;
int main(){
		ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num;
	int problem_num;
	cin>> num;
	cin>> problem_num;
	map<string, int> mp;
	map<int, string> mp2;
	string temp;
	vector<string> ans;
	
	for(int i=0; i<num; i++){
	cin>> temp;
	mp[temp] = i+1;
	mp2[i+1] = temp;
	}
	for(int i=0; i<problem_num; i++){
	 cin>> temp;
	 if(atoi(temp.c_str()))
	 cout<< mp2[atoi(temp.c_str())]<<"\n";
	 else{
	 cout<< mp[temp] << "\n";
	 }
	}

	return 0;
}
