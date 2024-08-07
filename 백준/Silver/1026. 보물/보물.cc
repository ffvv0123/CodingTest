#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 0;
int A[51], B[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i < N; i++) cin >> A[i];
    for(int i=0; i < N; i++) cin >> B[i];

    sort(A, A+N);
    sort(B, B+N, greater<int>());

    for(int i=0; i < N; i++) answer += A[i] * B[i];

    cout << answer;

    return 0;
}