#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    stack<char> leftStack, rightStack;
    for (char c : s) {
        leftStack.push(c);
    }

    for (int i = 0; i < n; ++i) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (!leftStack.empty()) {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        } else if (command == 'D') {
            if (!rightStack.empty()) {
                leftStack.push(rightStack.top());
                rightStack.pop();
            }
        } else if (command == 'B') {
            if (!leftStack.empty()) {
                leftStack.pop();
            }
        } else if (command == 'P') {
            char c;
            cin >> c;
            leftStack.push(c);
        }
    }

    // Collect result
    string result;
    while (!leftStack.empty()) {
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
    while (!rightStack.empty()) {
        result += rightStack.top();
        rightStack.pop();
    }

    cout << result << endl;

    return 0;
}
