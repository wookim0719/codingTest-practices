#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
const int INF= 987654321;
int n,goal;
int ret= INF;
set<int> mp[9];

int solution(int N, int number) {
    n=N;
    goal= number; 
    int temp=n;
    for(int i=1; i<=8; i++){
        mp[i].insert(temp);
        temp= temp*10+n;
        cout<<temp;
    }
    
    for(int i=1; i<=8; i++){
        for(int j=1; j<i; j++){
            for(int a: mp[i-j]){
                for(int b: mp[j]){
                    mp[i].insert(a+b);
                    mp[i].insert(a*b);
                    if(a>b)
                    mp[i].insert(a-b);
                    if(a/b>0&&(a%b==0))
                    mp[i].insert(a/b);
                }
            }
        }
    }
    
    for(int i=1; i<=8; i++){
        for(int t: mp[i]){
            if(t==number)
                return i;
        }
    }
    return -1;
}
