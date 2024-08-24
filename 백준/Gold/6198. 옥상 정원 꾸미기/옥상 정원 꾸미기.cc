#include <iostream>
#include <stack>
using namespace std;

int N;
long long h;
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long answer = 0;
    cin >> N;

    //s.push({1000000001, 0});
    for(int i=1; i <= N; i++) {
        cin >> h;

        while(!s.empty() && s.top().first <= h) s.pop();
        answer += s.size();
        s.push({h, i});
    }

    cout << answer;
    return 0;
}