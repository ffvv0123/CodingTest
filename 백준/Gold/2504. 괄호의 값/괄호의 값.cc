#include <iostream>
#include <stack>
using namespace std;

int answer = 0, tmp_ans = 1;
string input_data;
stack<char> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> input_data;
    int len = input_data.size();
    

    for(int i=0; i < len; i++) {
        if (input_data[i] == '(') {
            tmp_ans *= 2;
            s.push(input_data[i]);
        }
        else if (input_data[i] == '[') {
            tmp_ans *= 3;
            s.push(input_data[i]);
        }
        else if (input_data[i] == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }

            if (input_data[i-1] == '(') answer += tmp_ans;
            s.pop();
            tmp_ans /= 2;
        }
        else if (input_data[i] == ']') {
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }

            if (input_data[i-1] == '[') answer += tmp_ans;
            s.pop();
            tmp_ans /= 3;
        }
    }

    if (s.size()) cout << 0;
    else cout << answer;

    return 0;
}