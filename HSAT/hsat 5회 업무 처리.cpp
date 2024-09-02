#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> g;
int h,k,r;
struct node{
    queue<int> left;
    queue<int> right;
};
int ret;
node a[2048];
queue<g> tq;

int main(int argc, char** argv)
{
    cin>>h>>k>>r;
    int s= pow(2,h);
    int e= pow(2,h+1)-1;
  //  cout<<s<<" "<<e<<"\n";
    for(int i=s; i<=e; i++){
       for(int j=0; j<k; j++){
           int temp;
           cin>>temp;
           a[i].left.push(temp);
       }
    }
    int d=1;
    while(true){
        if(d>r) break;
        // 부서장이 처리
        if(d%2){
            if(a[1].left.size()){
               ret+= a[1].left.front();
                a[1].left.pop();
        }
        }
        else{
            if(a[1].right.size()){
                ret+=a[1].right.front();
                a[1].right.pop();
            }
        }
        //맨 밑에 처리하기
        for(int i=s; i<=e; i++){
               if(a[i].left.size()){
                 int temp=0;
                 temp = a[i].left.front();
                 a[i].left.pop();
                    if(i%2)
                     tq.push({{temp,i/2},1});
                   else{
                     tq.push({{temp,i/2},0});
                   }
               } 
            }
        //그 위에 처리하기
        for(int i=s-1; i>1; i--){
            //홀수날
            if(d%2){
               if(a[i].left.size()){
                int temp=a[i].left.front();
                   a[i].left.pop();
                   if(i%2==0){
                    tq.push({{temp,i/2},0});
                   }
                   else
                   tq.push({{temp,i/2},1});
               } 
            }
            //짝수날
            else{
                 if(a[i].right.size()){
                  int temp=a[i].right.front();
                     a[i].right.pop();
                  if(i%2==0){
                    tq.push({{temp,i/2},0});
                   }
                   else
                   tq.push({{temp,i/2},1});
               } 
            }
        }
        //임시로 가지고 있던 값들 큐에 넣어주기
        while(tq.size()){
            auto v= tq.front();
            auto value= v.first;
            auto rol= v.second;
            tq.pop();
            if(rol%2==0){
                a[value.second].left.push(value.first);
           //     cout<<value.second<<" "<<value.first<<"left"<<"\n";
            }
            else{
                a[value.second].right.push(value.first);
        //    cout<<value.second<<" "<<value.first<<"right"<<"\n";
            }
        }
        d=d+1;
        // for(int i=1; i<=pow(2,h+1)-1; i++){
        //     cout<<i<<" "<<a[i].left.size()<<" "<<a[i].right.size()<<"\n";
        // }
        // cout<<d<<"\n";
        }
    cout<<ret;
   return 0;
}
