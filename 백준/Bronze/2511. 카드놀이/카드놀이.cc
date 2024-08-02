#include <iostream>
using namespace std;

int A[10], B[10];
int A_score = 0, B_score = 0;
char last_winner = 'D';


int main() {
    for(int i=0; i < 10; i++)
        cin >> A[i];

    for(int i=0; i < 10; i++)
        cin >> B[i];

    for(int i=0; i < 10; i++) {
        if (A[i] > B[i]) {
            last_winner = 'A';
            A_score += 3;
        }
        else if (A[i] < B[i]) {
            last_winner = 'B';
            B_score += 3;
        }
        else {
            A_score += 1;
            B_score += 1;
        }
    }

    cout << A_score << ' ' << B_score << '\n';
    if(A_score > B_score) cout << 'A';
    else if (A_score < B_score) cout << 'B';
    else {
        if (last_winner == 'A') cout << 'A';
        else if (last_winner == 'B') cout << 'B';
        else cout << 'D';
    }

    return 0;
}