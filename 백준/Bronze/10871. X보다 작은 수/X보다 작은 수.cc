#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    
    int A[10001];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < X) 
            cout << A[i] << ' ';
    }

    return 0;
}