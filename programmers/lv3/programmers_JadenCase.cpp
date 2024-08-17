#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    queue<char> q;
    int p=0;
    while(true){
    if(p==s.size())break;
     if(s[p]==' '){
         int c=0;
         while(q.size()){
           char t = q.front();
           q.pop();
            if(c==0&&((t-'0')<0||(t-'0')>9)){
                if((t-'a')>=0&&(t-'a')<=26){
                int temp= t-'a';
                char temp2= temp+'A';
                    t=temp2;
                }
               // cout<<temp2<<"\n";
                answer+=t;   
            }
             else{
                if(t-'A'>=0&&t-'A'<=26){
                    t = t-'A'+'a';
                } 
                answer+=t;
             }
            c++;
         }
         answer+=' ';
         }
        else{
          q.push(s[p]);  
        }
       p++;
    }
    int c2=0;
    while(q.size()){
        char tt= q.front();
        q.pop();
        if(c2==0){
            if((tt-'a')>=0&&(tt-'a')<=26)
                tt=tt-'a'+'A';
        }
        else{
            if((tt-'A')>=0&&(tt-'A')<=26){
                tt=tt-'A'+'a';
            }
        }
        c2++;
        answer+=tt;
    }

    return answer;
}
