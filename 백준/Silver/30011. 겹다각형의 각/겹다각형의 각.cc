#include <iostream>
using namespace std;

int N;
int answer = 0;
int figure[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++)
        cin >> figure[i];
    
    if (N == 1) {
        answer = (figure[0] - 2) * 180;
    }
    else {
        answer = (figure[0] - 2) * 180;
        for(int i=1; i < N; i++)
            answer += figure[i] * 180;
    }

    cout << answer;

    return 0;
}