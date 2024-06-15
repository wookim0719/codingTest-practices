#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> c;

vector<vector<int>> makeCalendar(int weekday, int days){
	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
			c[i].push_back(0);
		}
	}
	
	return c;
}

void display(const vector<vector<int>> & calendar, const string& delimiter, const string& blank){
	
	cout<<0;
	return;
}




int main(){
	int weekday, days;
	string delimiter, blank;
	cin>>weekday>>days;
	cin>>delimiter>>blank;
	
	vector<vector<int>> calendar = makeCalendar(weekday,days);
	
	return 0;
}
