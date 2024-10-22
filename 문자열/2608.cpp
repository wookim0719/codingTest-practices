#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
string res="";
int main(){
	mp['I']=1;
	mp['V']=5;
	mp['X']=10;
	mp['L']=50;
	mp['C']=100;
	mp['D']=500;
	mp['M']=1000;
	int ret=0;
	
	for(int i=0; i<2; i++){
		string temp;
		cin>>temp;
		for(int j=0; j<temp.size(); j++){
			if(j<temp.size()-1){
				if(mp[temp[j]]<mp[temp[j+1]]){
					ret-= mp[temp[j]];
				}	
				else{
					ret+=mp[temp[j]];
				}
			}
			else
			ret+=mp[temp[j]];
		}
	//	cout<<ret<<"\n";
	}
	cout<<ret<<"\n";
	//ret=3999;
	int a= ret/1000;
	ret %=1000;
	if(a>0){
		while(a--){
				res+='M';
			}	
	}
	int b= ret/100;
	ret %=100;
	if(b>0){
		if(b==9){
			res+="CM";
		}
		else if(b==5){
			res+='D';
		}
		else if(b>5){
			b-=5;
			res+='D';
			while(b--){
				res+='C';
			}
		}
		else if(b==4){
			res+="CD";
		}
		else{
			while(b--){
				res+='C';
			}	
		}
	}
	int c= ret/10;
	ret%=10;
	if(c>0){
		if(c==9){
			res+="XC";
		}
		else if(c==5){
			res+='L';
		}
		else if(c>5){
			c-=5;
			res+='L';
			while(c--){
				res+='X';
			}
		}
		else if(c==4){
			res+="XL";
		}
		else{
			while(c--){
				res+='X';
			}	
		}	
	}
	//cout<<ret<<"\n";
	if(ret>0){
		if(ret==9){
			res+="IX";
		}
		else if(ret==5){
			res+='V';
		}
		else if(ret>5){
			ret-=5;
			res+='V';
			while(ret--){
				res+='I';
			}
		}
		else if(ret==4){
			res+="IV";
		}
		else{
			while(ret--){
				res+='I';
			}	
		}	
	}
	cout<<res<<"\n";
	return 0;
}
