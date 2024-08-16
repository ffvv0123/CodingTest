#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, answer = 0;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<vector<int>> point(N+1);

    int a, b;
    for(int i=0; i < N; i++) {
        cin >> a >> b;
        point[b].push_back(a);
    }

    for(int i=1; i <= N; i++) {
        if(point[i].size() <= 1) continue;
        sort(point[i].begin(), point[i].end());

        answer += (point[i][1] - point[i][0]) + (point[i][point[i].size() - 1] - point[i][point[i].size() - 2]);
        for(int j = 1; j < point[i].size() - 1; j++) {
            answer += min(point[i][j] - point[i][j-1], point[i][j+1] - point[i][j]);
        }
    }
    
    cout << answer;

    return 0;
}