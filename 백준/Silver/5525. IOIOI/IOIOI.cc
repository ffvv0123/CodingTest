#include <iostream>
#include <algorithm>
using namespace std;

int N, M, length, answer = 0;
string S, P = "I";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> M;
    cin >> S;

    for(int i=0; i < M; i++) 
        S += "OI";
    length = 2 * N + 1;

    int cnt = 0; bool checker = false;
    for(int i=0; i < M; i++) { 
        if (S[i] == 'I' && checker == false) {
            checker = true;
            cnt++;
        }
        else if (checker == true) {
            if (S[i-1] == S[i]) {
                checker = false;
                if(cnt >= length)
                    answer += (cnt - length) / 2 + 1;
                cnt = 0;

                if (S[i] == 'I') {
                    checker = true;
                    cnt++;
                }
            }
            else {
                cnt++;
            }
        }
    }
    if (checker && cnt >= 3) {
        if(cnt >= length)
            answer += (cnt - length) / 2 + 1;
    }

    cout << answer;

    return 0;
}