#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int visited[8];
int ret;
int len;
int a[10000000];
string o;

bool issosu(string temp){
    int num=0;
    for(int i=0; i<temp.size(); i++){
        num += (temp[i]-'0')*pow(10,temp.size()-1-i);
    }
    if(a[num])return false;
    a[num]=1;
    if(num==0) return false;
    if(num==1) return false;
    else if(num==2) return true;
    else{
      for(int i=2; i<num; i++){
          if(num%i==0) return false;
      }
    }
    return true;
}

void go(string ss){
    cout<<ss<<"\n";
    if(issosu(ss)) {
        ret++; 
    }   
    for(int i=0; i<len; i++){
       if(!visited[i]){
            visited[i]=1;
            go(ss+o[i]);
            visited[i]=0;
        }
    }

    return ;
}

int solution(string numbers) {
    o= numbers;
    len=o.size();
    go("");
    int answer = ret;
    return ret;
}
