#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool matches(int opening, int closing) {
    switch(opening) {
        case 0: return closing == 9;  // ( )
        case 1: return closing == 8;  // [ ]
        case 2: return closing == 7;  // { }
        case 3: return closing == 6;  // < >
        case 4: return closing == 5;  // (* *)
        default: return false;
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        stack<int> stk;
        int pos = 1;
        bool error = false;

        for (size_t i = 0; i < line.size(); ++i) {
            int ch = -1;

            if (line[i] == '(') {
                if (i + 1 < line.size() && line[i + 1] == '*') {
                    ch = 4; // (* as one token
                    ++i;
                } else {
                    ch = 0; // (
                }
            } else if (line[i] == '[') ch = 1;
            else if (line[i] == '{') ch = 2;
            else if (line[i] == '<') ch = 3;
            else if (line[i] == '*') {
                if (i + 1 < line.size() && line[i + 1] == ')') {
                    ch = 5; // *) as one token
                    ++i;
                }
            } else if (line[i] == '>') ch = 6;
            else if (line[i] == '}') ch = 7;
            else if (line[i] == ']') ch = 8;
            else if (line[i] == ')') ch = 9;

            if (ch == -1) {
                ++pos;
                continue;
            }

            if (ch <= 4) {
                stk.push(ch);
            } else {
                if (stk.empty() || !matches(stk.top(), ch)) {
                    cout << "NO " << pos << endl;
                    error = true;
                    break;
                }
                stk.pop();
            }

            ++pos;
        }

        if (error) continue;

        if (!stk.empty()) {
            cout << "NO " << pos << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}