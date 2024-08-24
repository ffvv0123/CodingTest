#include <iostream>
#include <stack>
using namespace std;

int N;
long long h;
stack<pair<long long, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long answer = 0;
    cin >> N;

    s.push({1000000001, 0});

    for(int i=1; i <= N; i++) {
        cin >> h;
        if (s.top().first <= h) {
            while(h >= s.top().first) {
                answer += i - s.top().second - 1;
                s.pop();
            }
        }
        s.push({h, i});
    }

    while(s.size() > 1) {
        answer += N - s.top().second;
        s.pop();
    }

    cout << answer;
    return 0;
}