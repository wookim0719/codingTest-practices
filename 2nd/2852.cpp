#include<bits/stdc++.h>
using namespace std;
int n;
int a,b;
int time1,time2;
string current_time="";

string inttostrint(int i){
	string str;
	int min = i/60;
	int sec = i%60;
	char k = min/10+'0';
	char j = min%10+'0'; 
	str+= k;
	str+= j;
	str+=':';
	 k = sec/10+'0';
	 j = sec%10+'0'; 
	str+= k;
	str+= j;
	return str;	
}

int stringtoint(string t){
	string m = t.substr(0,2);
	string s = t.substr(3);
	int value=0;
	for(int i=1; i>=0; i--){
		int tt=0;
		tt += m[i]-'0';
		if(i==0) tt *=10;
		value+=tt;
	}
	value = value*60;
		for(int i=1; i>=0; i--){
		int tt=0;
		tt += s[i]-'0';
		if(i==0) tt *=10;
		value+=tt;
	}
	return value;
}

void calculate(int temp, string temp2){
	if(current_time!= ""){
		if(a>b){
			time1 += stringtoint(temp2) - stringtoint(current_time);	
		}	
		else if(b>a){
			time2 += stringtoint(temp2) - stringtoint(current_time);	
		}
	}
	if(temp==1) a++;
	else b++;
	current_time = temp2;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		string temp2;
		cin>>temp>>temp2;
		calculate(temp,temp2);
	}
	
	//마지막 시간을 기준으로 계산한 번 더해줘야됨. 
	if(current_time!= "48:00"){
		if(a>b){
		time1 += stringtoint("48:00") - stringtoint(current_time);	
		}
		else if(a<b){
		time2 += stringtoint("48:00") - stringtoint(current_time);	
		}
	}
	
	
	cout<<inttostrint(time1)<<"\n"<< inttostrint(time2);
	
	return 0;
}
