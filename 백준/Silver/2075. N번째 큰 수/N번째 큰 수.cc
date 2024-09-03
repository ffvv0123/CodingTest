#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, cnt = 0;
int chart[1501][1501];
priority_queue<tuple<int, int, int>> pq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> chart[i][j];
        }
    }

    for(int i=0; i < N; i++) {
        pq.push({chart[N-1][i], N-1, i});
    }
    while(cnt != N-1) {
        tuple<int, int, int> cur = pq.top();
        int idx = get<2>(cur);
        
        pq.pop();
        cnt++;
        
        pq.push({chart[get<1>(cur) - 1][idx], get<1>(cur) - 1, idx});
    }
    
    cout << get<0>(pq.top());

    return 0;
}