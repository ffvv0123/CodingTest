/**
 * ((( ()     ()   )
 * 3개  |  3개  |  컷, 이어짐
 * -> 레이저: 괄호 개수만큼 더하기
 * -> 닫히면 닫힌거만 따로 추가, 누적되는거 바꾸기
 */

#include <iostream>
#include <stack>
using namespace std;

string lazor;
stack<char> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> lazor;
    lazor += ' ';

    int stack = 0, answer = 0;

    for(int i=0; i < lazor.length(); i++) {
        if (lazor[i] == '(' && lazor[i+1] == ')') {
            answer += stack;
            i++;
        }
        else if (lazor[i] == '(') {
            stack++;
        }
        else if (lazor[i] == ' ') break;
        else {
            stack--;
            answer++;
        }
    }

    cout << answer;


    return 0;
}