#include<bits/stdc++.h>
using namespace std;
vector<int> v[10];
int n,k,p,x;
map<int,int> mp;
int ret;
void go(int remain,int dig,string now){
	if(dig==k){
		int tt= stoi(now);
		if(mp[tt]!=1&&tt<=n&&tt>0){
		ret++;
		mp[tt]=1;
	//	cout<<tt<<"\n";
		}
		return;
}
	int value=now[dig]-'0';
//	cout<<remain<<" "<<dig<<" "<<now<<" "<<value;
	for(int i=0; i<10; i++){
		if(remain>=v[value][i]){
		//	cout<<i<<"\n";
			char t= now[dig];
			now[dig]=i+'0';
			go(remain-v[value][i],dig+1,now);
			now[dig]= t;
		//	cout<<value;
		}
		//go(remain,dig+1,now);
	}
	return;
}

int main(){
	int temp[10][10]={
            {0,4,3,3,4,3,2,3,1,2},
            {4,0,5,3,2,5,6,1,5,4},
            {3,5,0,2,5,4,3,4,2,3},
            {3,3,2,0,3,2,3,2,2,1},
            {4,2,5,3,0,3,4,3,3,2},
            {3,5,4,2,3,0,1,4,2,1},
            {2,6,3,3,4,1,0,5,1,2},
            {3,1,4,2,3,4,5,0,4,3},
            {1,5,2,2,3,2,1,4,0,1},
            {2,4,3,1,2,1,2,3,1,0}
    };
    
    for(int i=0; i<10; i++){
    	for(int j=0;j<10; j++){
    		v[i].push_back(temp[i][j]);
		}
	}
	cin>>n>>k>>p>>x;
	mp[x]=1;
	string xx= to_string(x);
    xx = string(k - xx.size(), '0') + xx; // Pad with leading zeros

	go(p,0,xx);
	
	cout<<ret;
	return 0;
}
