#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
  stack<char> st;
    int n = number.size();
    for (int i = 0; i < n; ++i) {
        // ���� ���ڰ� ������ �ֻ��� ���ں��� ũ�� �ֻ��� ���ڸ� ����
        while (!st.empty() && k > 0 && st.top() < number[i]) {
            st.pop();
            --k;
        }
        st.push(number[i]);
    }

    // ���ÿ� ���� ���ڵ� ��, ���� �ʿ��� ���ڸ� ����
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
