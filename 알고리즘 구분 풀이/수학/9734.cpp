#include<bits/stdc++.h>
using namespace std;

int maxx(int a,int b){
	while(b!=0){
		int temp = b;
		b= a%b;
		a=temp;
	}
	return a;
}

int main(){
	string num;
	while(cin>>num){
		queue<char> q;
		int idx,idx2;
		for(int i=0; i<num.size(); i++){
			if(num[i]=='('){
				idx= i;
			}
			if(num[i]=='.'){
				idx2=i;
			}
		}
		for(char c: num){
			if(c!='('&&c!=')')
			q.push(c);
		}
		string temp;
		while(q.size()){
			temp+=q.front();
			q.pop();
		}
	//	cout<<idx-idx2-1<<" "<<num.size()-idx2-3<<" ";
		double pri = stod(temp);
	//	cout<<pri<<"\n";
		int val = pow(10,num.size()-idx2-3)-pow(10,idx-idx2-1);
		int temp1 = pri * pow(10,idx-idx2-1);
		int temp2 = pri * pow(10,num.size()-idx2-3);
		int res= temp2-temp1;
		int maax= maxx(res,val);
		cout<<num<<" "<<'='<<" "<<res/maax<<" / "<<val/maax<<"\n";		
	}
	
	
	return 0;
}
