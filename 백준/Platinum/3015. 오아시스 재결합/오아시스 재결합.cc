#include <iostream>
#include <stack>
using namespace std;

int N, h;
int height[500001];
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    long long answer = 0;
    while(N--) {
        cin >> h;
        int cnt = 1;

        while(!s.empty() && s.top().first <= h) {
            answer += s.top().second;

            if (s.top().first == h) {
                cnt += s.top().second;
            }
            s.pop();
        }
        if (!s.empty()) answer++;
        s.push({h, cnt});
    }

    cout << answer;
    
    return 0;
}