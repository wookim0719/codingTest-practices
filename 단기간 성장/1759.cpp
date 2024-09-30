#include<bits/stdc++.h>
using namespace std;
int c,n;
vector<char> v;

void go(string temp, int s){
	if(temp.size()==c) {
		int cnt=0;
		int cnt2=0;
		for(int i=0; i<temp.size(); i++){
			if(temp[i]=='a'||temp[i]=='e'||temp[i]=='i'||temp[i]=='o'||temp[i]=='u'){
				cnt++;
			}
			else{
				cnt2++;
			}
		}
		if(cnt>0&&cnt2>=2) {
			cout<<temp<<"\n";
		}
		return;
	}
	for(int i=0; i<v.size(); i++){
		if(i>s){
			go(temp+v[i],i);
		}
	}
	return;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n;
	for(int i=0; i<n; i++){
		char temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	go("",-1);
	
	return 0;
}
