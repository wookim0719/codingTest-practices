#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
queue<pair<int,int>> q2;
queue<pair<int,int>> q3;

int solution(vector<int> p, int location) {
    for(int i=0; i<p.size(); i++){
        q.push({p[i],i});
    }
    int temp=0;
    int cnt=0;
    while(q.size()){
        cout<<q.front().second<<"\n";
      if(q.front().first>temp) {
          temp= q.front().first;
          while(q2.size()){
              q3.push(q2.front());
              q2.pop();
          }
        q2.push(q.front());
        q.pop();
      }  
       else{
           q2.push(q.front());
           q.pop();
       } 
       if(q.size()==0){
           if(q2.size()){
            //cout<<q2.front().first<<" "<<q2.front().second<<q3.size()<<"\n";
            cnt++;
           if(q2.front().second == location){
             break;  
           }
            q2.pop(); 
            temp=0;
           while(q2.size()){
               q.push(q2.front());
               q2.pop();
           } }
           if(q3.size()){
              while(q3.size()){
                  q.push(q3.front());
                  q3.pop();
              } 
           }
       }
    }
    int answer = cnt;
    return answer;
}
