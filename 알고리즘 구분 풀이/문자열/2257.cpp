#include <bits/stdc++.h>
using namespace std;
string s;
int idx=0;
int ret;
map<char,int> mp;
int go(){
  //cout<<idx<<" "<<mp[s[idx]]<<"\n";
  int res=0;
  int temp=0;
  while(true){
    //cout<<idx<<" "<<res<<"\n";
    if(s[idx]==')'){
      res +=temp;
      return res;
    }
    if(s[idx]=='('){
      idx++;
      res+=temp;
      temp=0;
      temp+= go();
    }
    else if((s[idx]-'0')>=0 && (s[idx]-'0')<=9){
        res+= temp*(s[idx]-'0');
        temp=0;
      }
      else{
        res+=temp;
        temp=0;
        temp += mp[s[idx]];
      }
      idx++;
  }
  res +=temp;
  return res;
}

int main() 
{   
    cin>>s;
    mp['H']=1;
    mp['C']=12;
    mp['O']=16;
    int temp=0;
    while(true){
     // cout<<idx<<" "<<ret<<" "<<temp<<"\n";
      if(idx== s.size()) break;
      if(s[idx] == '('){
        ret+=temp;
        idx++;
        temp = go();
        //cout<<temp<<"\n";
      }
      else if((s[idx]-'0')>=0 && (s[idx]-'0')<=9){
        ret+= temp*(s[idx]-'0');
        temp=0;
      }
      else{
        ret+=temp;
        temp=0;
        temp += mp[s[idx]];
      }
      idx++;
    }
    ret+=temp;
      
    cout<<ret;
    
    return 0;
}