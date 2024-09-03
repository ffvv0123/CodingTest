#include <iostream>
using namespace std;

int n;
int matrix[16][16];

long long coef(int n) {
    long long result = 1;
    for(int i=1; i <= n; i++) {
        result = result * (n + i) / i;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            cin >> matrix[i][j];

    long long result = coef(n);
    cout << result << ' ' << n * n;

    return 0;
}