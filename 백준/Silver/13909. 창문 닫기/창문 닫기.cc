#include <iostream>
using namespace std;

int N, answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    for(int i=1; i*i <= N; i++) {
        answer++;
    }

    cout << answer;

    return 0;
}