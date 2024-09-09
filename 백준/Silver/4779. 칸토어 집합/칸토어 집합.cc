#include <iostream>
#include <cmath>
using namespace std;

int N;
string answer;

void solution(int start, int end, bool checker) {
    int num = (end - start) / 3;
    if (num == 0 && checker) {
        return;
    }

    if (!checker) {
        for (int i = start; i < end; i++) {
            answer[i] = ' ';
        }
    }

    if (num == 0) return;

    solution(start, start + num, true);
    solution(start + num, start + 2 * num, false);
    solution(start + 2 * num, end, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        answer = "";
        
        int sol = pow(3, N);

        for (int i = 0; i < sol; i++) {
            answer += '-';
        }

        solution(0, sol, true);
        cout << answer << '\n';
    }

    return 0;  
}