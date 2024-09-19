#include<iostream>
#include<bits/stdc++.h>

using namespace std;
string plain;
string key;
map<char,int> mp;
char a[5][5];
string ret;

int fiind(char c){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(a[i][j]==c){
                return i*10+j;
            }
        }
    }
    return -1;
}


string go(string s){
    int loc1= fiind(s[0]);
    int loc2= fiind(s[1]);
   // cout<<loc1<<" "<<loc2<<"\n";
    string res="";
    if((loc1/10) == (loc2/10)){
        int ii= loc1/10;
        int loc1J= ((loc1%10)+1)%5;
        int loc2J= ((loc2%10)+1)%5;
        res+= a[ii][loc1J];
        res+= a[ii][loc2J];
    }
    else if((loc1%10)==(loc2%10)){
        int jj= loc1%10;
        int loc1I= ((loc1/10)+1)%5;
        int loc2I= ((loc2/10)+1)%5;
         res+= a[loc1I][jj];
         res+= a[loc2I][jj];
    }
    else{
        int loc1J= (loc1%10);
        int loc2J= (loc2%10);
        res+= a[loc1/10][loc2J];
        res+= a[loc2/10][loc1J];
    }
    return res;
}

int main(int argc, char** argv)
{
    cin>>plain>>key;
    queue<char> q;
    for(int i=0; i<key.size(); i++){
        if(!mp[key[i]]){
            mp[key[i]]=1;
            q.push(key[i]);
        }
    }
    for(int i=0; i<26; i++){
        if(i=='J'-'A')continue;
        if(!mp[i+'A']){
            q.push('A'+i);
            mp[i+'A']++;
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int temp =q.front();
            q.pop();
            a[i][j]=temp;
        }
    }
    queue<char> q2;
    for(int i=0; i<plain.size(); i++){
        q2.push(plain[i]);
    }
    string temp;
    while(q2.size()){
        if(temp==""){
            char f= q2.front();
            q2.pop();
            temp+=f;
        }
        else{
            char f= q2.front();
            if(f!=temp[0]){
                q2.pop();
                temp+=f;
               ret+= go(temp);
        //        cout<<temp<<"\n";
                temp="";
            }
            else{
                if(temp[0]!='X'){
                    temp+='X';
                }
                else{
                    temp+='Q';
                }
                  ret+=  go(temp);
          //      cout<<temp<<"\n";
                    temp="";
            }
        }
    }
    //마지막에 남아있는 값 처리해주어야함.
    if(temp.size()){
        temp+='X';
      //  cout<<temp;
        ret+=go(temp);
    }

    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout<<a[i][j];
    //     }
    //     cout<<"\n";
    // }
    cout<<ret;
   return 0;
}
