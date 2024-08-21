#include <iostream>
#include <stack>
using namespace std;

int N, answer = 0;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    answer = N;

    while(N--) {
        stack<char> s;
        bool checker = true;
        cin >> str;

        for(int i=0; i < str.length(); i++) {
            if (s.empty()) {
                s.push(str[i]);
            }
            else {
                if (s.top() == str[i]) s.pop();
                else s.push(str[i]);
            }
        }
        if (!s.empty()) answer--;
    }

    cout << answer;

    return 0;
}