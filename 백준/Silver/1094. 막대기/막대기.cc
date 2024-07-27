#include <iostream>
using namespace std;

unsigned int X;
int answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> X;

    for(int i=0; X != 0; i++) {
        X = X & (X-1);
        answer++;
    }

    cout << answer;

    return 0;
}