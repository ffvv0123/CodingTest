#include <iostream>
#include <deque>
using namespace std;

int N, M;
int A[100001], B[100001], C[100001];
deque<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) cin >> A[i];
    for(int i=0; i < N; i++) {
        cin >> B[i];
        if(A[i] == 0) q.push_front(B[i]);
    }

    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> C[i];
        q.push_back(C[i]);
    }

    for(int i=0; i < M; i++) {
        cout << q.front() << ' ';
        q.pop_front();
    }

    return 0;
}