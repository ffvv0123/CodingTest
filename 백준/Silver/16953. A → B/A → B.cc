#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int A, B;
    int answer = 0;
    cin >> A >> B;

    while(true) {
        if (B % 2 == 1) {
            if (B % 10 != 1) {
                answer = -1;
                break;
            }
            else {
                B /= 10;
                answer++;
            }
        }
        else {
            B /= 2;
            answer++;
        }
        if (B == A) {
            answer++;
            break;
        }
        if (B < A) {
            answer = -1;
            break;
        }
    }
    cout << answer;
}