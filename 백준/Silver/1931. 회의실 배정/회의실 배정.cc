#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<pair<int, int>> meeting;

    for(int i=0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meeting.push_back({start, end});
    }

    sort(meeting.begin(), meeting.end(), compare);

    int answer = 1;
    int meeting_done = meeting[0].second;
    for(int i=1; i < N; i++) {
        if (meeting[i].first >= meeting_done) {
            meeting_done = meeting[i].second;
            answer += 1;
        }
    }
    cout << answer;

    return 0;
}