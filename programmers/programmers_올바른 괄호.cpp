#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
queue<char> q;


bool solution(string s)
{
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') q.push('(');
        else if(q.front()=='('){
            q.pop();
        }
        else q.push(')');
    }
    
    bool answer = true;
    if(q.size()) answer= false;


    return answer;
}
