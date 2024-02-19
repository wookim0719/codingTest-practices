#include <bits/stdc++.h>
using namespace std;

int n;
int A = 0;
int B = 0;
int a_sum = 0;
int b_sum = 0;
int o;
string s;
string prev_time;

string print(int a){ 
    string d = "00" + to_string(a / 60); 
    string e = "00" + to_string(a % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

int changesec(string a){
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int &sum, string s){
	sum += (changesec(s) - changesec(prev_time));
}

int main(){
	cin>>n;
	int prevTeam =0;
  for(int i = 0; i < n; i++){
        cin >> o >> s; 
        if(A > B)go(a_sum, s);
        else if(B > A)go(b_sum, s);
		o == 1 ? A++ : B++;
        prev_time = s; 
    } 
	 if(A > B)go(a_sum, "48:00");
    else if(A < B)go(b_sum, "48:00"); 
	cout<< print(a_sum) << "\n"<< print(b_sum);
	return 0;
}
