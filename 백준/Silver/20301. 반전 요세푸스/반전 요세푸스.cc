#include <iostream>
#include <deque> 
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    deque<int> dq;

    for (int i = 0; i < N; i++) {
        dq.push_back(i + 1);
    }

    int cnt = 0;
    bool check = true;

    while (!dq.empty()) {
        if (check) { // 순방향
            for (int i = 0; i < K - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        else { // 역방향
            for (int i = 0; i < K - 1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << '\n';
            dq.pop_back();
        }
        cnt++;
        if (cnt == M) {
            check = !check;
            cnt = 0;
        }

    }



}