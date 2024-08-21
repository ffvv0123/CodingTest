#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, M, x;
int idx, answer = 0;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i=1; i <= N; i++) dq.push_back(i);
    
    while(M--) {
        cin >> x;
        idx = find(dq.begin(), dq.end(), x) - dq.begin();

        while(dq.front() != x) {
            if (idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            answer++;
        }
        dq.pop_front();
    }
    
    cout << answer;
    
    return 0;
}