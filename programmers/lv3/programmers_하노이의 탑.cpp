#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;

void hanoi(int n, int start, int dest){
    if(n==1){
    v.push_back({start, dest});
        return;
    }   
    hanoi(n-1, start,6-start-dest);
    hanoi(1,start,dest);
    hanoi(n-1,6-start-dest,dest);
    return;
}

vector<vector<int>> solution(int n) {
    hanoi(n,1,3);
    vector<vector<int>> answer;
    answer=v;
    return answer;
}
