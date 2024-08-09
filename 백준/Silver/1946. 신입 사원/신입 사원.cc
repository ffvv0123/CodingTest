#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, N, answer;
    pair<int, int> applicant;

    cin >> T;
    while(T--) {
        vector<pair<int, int>> app_list; 
        cin >> N;
        for(int i=0; i < N; i++) {
            cin >> applicant.first >> applicant.second;
            app_list.push_back(applicant);
        }

        sort(app_list.begin(), app_list.end());
        answer = 1;

        int idx = 0;
        for(int i=1; i < N; i++) {
            if (app_list[idx].second > app_list[i].second) {
                answer++;
                idx = i;
            }
        }
        
        cout << answer << '\n';
    }

    return 0;
}