#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
  stack<char> st;
    int n = number.size();
    for (int i = 0; i < n; ++i) {
        // 현재 숫자가 스택의 최상위 숫자보다 크면 최상위 숫자를 제거
        while (!st.empty() && k > 0 && st.top() < number[i]) {
            st.pop();
            --k;
        }
        st.push(number[i]);
    }

    // 스택에 남은 숫자들 중, 실제 필요한 숫자만 추출
    while (k > 0) {
        st.pop();
        --k;
    }

    string answer = "";
    while (!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }
    
    return answer;
}
