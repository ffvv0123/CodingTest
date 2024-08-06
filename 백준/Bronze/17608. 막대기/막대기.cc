#include <iostream>
#include <stack>
using namespace std;

int N, h;
int answer = 0, max_height = -1;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> h;
        s.push(h);
    }

    for(int i=0; i < N; i++) {
        if (max_height < s.top()) {
            answer++;
            max_height = s.top();
        }
        s.pop();
    }
    cout << answer;

    return 0;
}