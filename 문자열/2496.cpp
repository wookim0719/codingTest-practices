#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
vector<string> v;
string ret;
int idx=0;
char before[23];
char after[23];
char des[23];

bool isPossible(string k){
	v[idx] = k;
//	cout<<k<<"\n";
	bool flag= true;
	for(int i=0; i<n; i++){
		int pos=i;
		for(int j=0; j<m; j++){
			if(v[j][pos]=='-'){
				pos+=1;
			}
			else if(pos>0&&v[j][pos-1]=='-'){
				pos-=1;
			}
		}
		if(pos!=des[i]){
			return false;
		}
	//	cout<<"\n";
	}
	return flag;
}

void go(string tmp, int num){
	if(num==s.size()-1){
		if(isPossible(tmp)){
			ret= tmp;
		}
		return;
	}
	else{
		go(tmp+'*',num+1);
		go(tmp+'-',num+1);
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>s;
	
	for(int i=0; i<m; i++){
		string temp;
		cin>>temp;
		if(temp[0]=='?') idx= i;
		v.push_back(temp);
	}	
	
	for(int i=0; i<s.size(); i++){
		des[i]=s[i];
	}
	
	for(int i=0; i<n; i++){
		int pos=i;
		char now= 'A'+i;
		for(int j=0; j<idx; j++){
			if(v[j][pos]=='-'){
				pos+=1;
			}
			else if(pos>0&&v[j][pos-1]=='-'){
				pos-=1;
			}
		}
		before[pos]= now;
	}
		
	for(int i=0; i<n; i++){
		int pos=i;
		char now= des[i];
		for(int j=m-1; j>idx; j--){
			if(v[j][pos]=='-'){
				pos+=1;
			}
			else if(pos>0&&v[j][pos-1]=='-'){
				pos-=1;
			}
		}
		after[pos]= now;
	//	cout<<pos<<" "<<after[pos]<<"\n";
	}
	bool flag=true;
	int pos=0;
	while(true){
		if(pos>n-2){
			break;
		}
		if(before[pos]== after[pos]){
			ret+='*';
			pos++;
		}
		else{
			if(before[pos]==after[pos+1]&&before[pos+1]==after[pos]){
			//	cout<<pos<<"\n";
				if(pos!=n-2){
					ret+="-*";	
				}
				else ret+='-';
				pos+=2;
			}
			else {
				flag=false;
				break;
			}	
		}
	}
	
	if(flag){
		cout<<ret;
	}
	else{
		for(int i=0; i<n-1; i++){
			cout<<'x';
		}
	}

	return 0;
}
