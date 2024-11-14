#include<bits/stdc++.h>
using namespace std;
string a;
string b;
string af;
string ae;
string bf;
string be;
vector<string> v;
vector<string> v2;
string ff;
string ee;
string ret;

int findIdx(string str){
	int idx=-1;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='*'){
			idx= i;
		}
	}
	return idx;
}

void mergeStr(){
	int iidx=-1;
	string ttt="";
	//cout<<ff<<" "<<ee<<"\n";
	for(int i=0; i<ff.size(); i++){
		string t1 = ff.substr(i);
		string t2 = ee.substr(0,t1.size());
		if(t1==t2) {
			ttt = ee.substr(t1.size());
			iidx=i;
			break;
		}
	}
	
	if(iidx!=-1){
	//	cout<<ff<<" "<<ttt<<"\n";
		ret=ff+ttt;
	}
	else{
		ret=ff+ee;	
	}
	return;
}

bool isAvailable(){
	bool flag1 = false;
	bool flag2 = false;
	if(af.find(bf)!=string::npos){
		flag1= true;
		if(bf.size()){
			string t3 = af.substr(0,bf.size());
			if(bf != t3){
				flag1=false;
			}
		}
		if(flag1) ff= af;	
	} 
	if(!flag1&&bf.find(af)!=string::npos){
		flag1= true;
		if(af.size()){
			string t3 = bf.substr(0,af.size());
			if(af != t3){
				flag1=false;
			}
		}
		if(flag1) ff= bf;	
	}
	if(ae.find(be)!=string::npos){
		flag2= true;
		if(be.size()){
			string t3 = ae.substr(ae.size()-be.size());
			if(be != t3){
				flag2=false;
			}
		}
		if(flag2) ee= ae;	
	}
	if(!flag2&&be.find(ae)!=string::npos){
		flag2= true;
		if(ae.size()){
			string t3 = be.substr(be.size()-ae.size());
			if(ae != t3){
				flag2=false;
			}
		}
		if(flag2) ee= be;	
	}
	if(flag1&&flag2) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	int idx1= findIdx(a);
	int idx2= findIdx(b);
	
	if(idx1!=-1){
		af = a.substr(0,idx1);
		ae = a.substr(idx1+1,a.size());	
	}
	if(idx2!=-1){
		bf = b.substr(0,idx2);
		be = b.substr(idx2+1,b.size());	
	}
	if(!isAvailable()){
		cout<<-1;
	}
	else{
		string sa= af+ae;
		string sb= bf+be;
		int aa = af.size()+ae.size();
		int bb = bf.size()+be.size();
		//cout<<ret<<"\n";
		bool flag=false;
		//if(ret.size()<aa||ret.size()<bb){
			if(aa>=bb&&sa.substr(0, bf.size()) == bf&&sa.substr(sa.size()-be.size(), be.size()) == be){
				if(bf.size()+be.size()<=aa){
					ret = sa;
					flag=true;
				}
			}
			if(!flag&&bb>=aa&&sb.substr(0, af.size()) == af&&sb.substr(sb.size()-ae.size(), ae.size()) == ae){
				if(af.size()+ae.size()<=bb){
					ret = sb;
					flag=true;
				}
			}
			if(!flag){
				mergeStr();
				if(ret.size()<aa||ret.size()<bb)
				ret= ff+ee;
			}
		//}

		cout<<ret;
	}		
	return 0;
}
