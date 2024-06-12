#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
map<int,string> mp;
vector<string> v;

bool solution(vector<string> phone_book) {
    bool answer= true;
    for(int i=0; i<phone_book.size(); i++){
        v.push_back(phone_book[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size()-1; i++){
        if(v[i+1].find(v[i])== 0)
            answer=false;
    }
    return answer;
}
