#include<bits/stdc++.h>
using namespace std;
int n;
int g;
vector<string> v;

bool check(string tttt){
	string t="";
	for (char c : tttt) {
        if (c != ' ') {
            t += c;
        }
    }
	int i=0;
	queue<int> nn;
	queue<char> op;
	string tt="";
	while(true){
		if(i==t.size()) break;
		if(t[i]!='+'&&t[i]!='-'){
	//		cout<<t[i]<<"\n";
		tt+=t[i];
		i++;
		}
		else{
	//		cout<<"op"<<t[i]<<"\n";
		nn.push(stoi(tt));
		tt="";
		op.push(t[i]);
		i++;
		}
	}
	nn.push(stoi(tt));
	int res=nn.front();
	nn.pop();
	while(op.size()){
		if(op.front()=='+'){
			res+=nn.front();
			nn.pop();
			//cout<<nn.front();
		}
		else if(op.front()=='-'){
			res-=nn.front();
			nn.pop();
		}
		op.pop();
	//	cout<<res<<"\n";
}
	
	if(res==0) return true;
	else return false;
}

void go(string temp, int c){
	if(c==g+1){
		if(check(temp)){
			v.push_back(temp);			
		}
		return;
	}
	go(temp+' '+to_string(c),c+1);
	go(temp+'+'+to_string(c),c+1);
	go(temp+'-'+to_string(c),c+1);
	return;
}


int main(){
	cin>>n;
	while(n--){
		v.clear();
		cin>>g;
		go("1",2);
		for(int i=0; i<v.size(); i++)
		cout<<v[i]<<"\n";
		cout<<"\n";
	}
//	cout<<check("1-2 3-4 5+6 7");//	
	return 0;
}
