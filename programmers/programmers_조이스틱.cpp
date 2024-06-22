#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
deque<int> dq;
deque<int> dq2;
int nn;

int goback(char n){
    int in='Z'-n+1;
        return in;
}
int gofor(char n){
    int in= n-'A';
    return in;
}
int shortcut(int c,int n){
    if(n<c) {
        return min(c-n,n-c+nn);
    }
    else{
           return min(n-c,c-n+nn); 
    }
}

int solution(string name) {
    nn= name.size();
    int res2=0;
    string name2= name;
    int n=0;
    int n2=0;
    int res=0;
    string ans ="";
    for(int i=0; i<name.size(); i++){
        ans+='A';
    }
    for(int i=0; i<name.size(); i++){
        if(name[i]!='A'){
            dq.push_back(i);
            dq2.push_back(i);
        }
    }
    int cnt=0; int cnt2=0;

    while(true){
       int temp=res;
       res = temp+goback(name[n]);
       res = min(res,temp+gofor(name[n]));
       name[n]='A';
        if(cnt==0&&dq.size()){
           int bb=shortcut(n,dq.front());
                res+=bb;
                n=dq.front();
                    dq.pop_front();
        }
       else if(dq.size()){
           int b=shortcut(n,dq.front());
           int b2=shortcut(n,dq.back());
           if(b<b2){ 
                res+=b;
                n=dq.front();
                    dq.pop_front();
                   }
           else {
              res+=b2;
              n=dq.back();
            dq.pop_back();
           }
       }
        if(name==ans)break;
        cnt++;
    }
     while(true){
       int temp2=res2;
       res2 = temp2+goback(name2[n2]);
       res2 = min(res2,temp2+gofor(name2[n2]));
       name2[n2]='A';
          if(cnt2==0&&dq2.size()){
           int bb2=shortcut(n2,dq2.back());
                res2+=bb2;
                n2=dq2.back();
                dq2.pop_back();
        }
       else if(dq2.size()){
          int b3=shortcut(n2,dq2.front());
           int b4=shortcut(n2,dq2.back());
           if(b3<b4){ 
                res2+=b3;
                n2=dq2.front();
                    dq2.pop_front();
                   }
           else {
              res2+=b4;
              n2=dq2.back();
            dq2.pop_back();
           }
       }
        if(name2==ans)break;
         cnt2++;
    }
    int ret= min(res,res2);
    return ret;
}
