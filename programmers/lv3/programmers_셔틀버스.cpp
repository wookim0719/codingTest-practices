#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> crew;
int current;
queue<int> q;
int ret;
int last=-1;

string solution(int n, int t, int m, vector<string> tt) {
    current= 9*60;
    for(int i=0; i<tt.size(); i++){
        int temp=0;
        temp+= (tt[i][0]-'0')*600;
        temp+= (tt[i][1]-'0')*60;
        temp+= (tt[i][3]-'0')*10;
        temp+= (tt[i][4]-'0');
        crew.push_back(temp);
    }
    sort(crew.begin(),crew.end());
    for(int a: crew){
        q.push(a);
    }
    int mm=m;
    while(n){
    if(n==0) break;
    mm=m;
    while(mm){
        if(q.size()&&q.front()<=current){
            if(n==1){
                last=q.front();
            }
            q.pop();
        }
        else{
            break;
        }
        mm--;
        if(mm==0) break;
        }
        if(mm>0) {
            last=-1;
            ret= current;
        }
        if(q.empty()){
            break;
        }
        n=n-1;  
        if(n==0) break;
        current+=t;
    }
    if(last!= -1){
        ret= last-1;
    }
    string answer = "";
   int h2 = ret/60;
   int m2 = ret%60;
    
   answer+=(h2/10)+'0';
   answer+=(h2%10)+'0';
   answer+=':';
   answer+=(m2/10)+'0';
   answer+=(m2%10)+'0';
    
    return answer;
}
