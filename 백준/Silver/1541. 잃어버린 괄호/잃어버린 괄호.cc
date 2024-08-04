/**
 * -가 나오면, 다음 -가 나오기 전까지 괄호 처리함.
 * 
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string formula;
bool check_minus = false;
int answer = 0;
stack<char> s;

int convert(bool minus) {
    int tmp, value = 0;

    tmp = minus ? -1 : 1;

    while(!s.empty()) {
        value += tmp * (s.top() - '0');
        s.pop();
        tmp *= 10;
    }
    
    return value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> formula;

    if(formula[0] != '-') formula = '+' + formula;

    for(int i = 0; i < formula.length(); i++) {
        if (formula[i] == '-') {
            answer += convert(check_minus);
            check_minus = true;
        }
        else if (formula[i] == '+') {
            answer += convert(check_minus);
        }
        else if (formula[i] != '+' && formula[i] != '-') {
            s.push(formula[i]);
            continue;
        }        
    }
    answer += convert(check_minus);

    cout << answer;

    return 0;
}