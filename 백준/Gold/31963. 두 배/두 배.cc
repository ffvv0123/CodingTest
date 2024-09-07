#include <iostream>
using namespace std;

int N, answer = 0;
int A[250001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) cin >> A[i];

    for(int i=1; i < N; i++) {
        if (A[i-1] > A[i]) {
            while(A[i-1] > A[i]) {
                A[i] *= 2;
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}