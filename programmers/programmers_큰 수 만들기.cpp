#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    stack<int> s;
    s.push(0);
    int num=1;
    while(true){
        while(s.size()){
          int f= s.top();
          if((number[f]-'0')<(number[num]-'0')){
            s.pop();
            number[f]='x'; 
            k--;
            if(k==0)break;
        }
        else break;
        }
        s.push(num);
        if(k==0) break;
        num++;
        if(num==number.size()){
         while(k!=0){
           int t= s.top();
            number[t]='x';
             s.pop();
             k--;
         }  
        }
    }
    queue<char> q;
    for(int i=0; i<number.size(); i++){
        if(number[i]!='x')
       q.push(number[i]); 
    }
    string answer = "";
    while(q.size()){
        answer+=q.front();
        q.pop();
    }
    return answer;
}
