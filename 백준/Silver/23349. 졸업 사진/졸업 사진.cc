/**
 * 이름 / 장소 / 시간
 * -> 가장 많은 사람이 제출한 (장소, 시간대) 쌍 선택
 * -> 위 조건이 여러개 -> 사전순으로 가장 앞
 * -> 위 조건이 또 여러개면 가장 빠른 시간대
 *
 * 가장 혼잡한 (장소, 시간대) 출력
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, start_time, end_time;
string name, place;

bool compare(pair<string, int> p1, pair<string, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    else return p1.first < p2.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> name_set;
    map<pair<string, int>, int> m;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name >> place >> start_time >> end_time;

        if (name_set.find(name) != name_set.end()) {
            continue;
        }

        name_set.insert(name);

        for (int t = start_time; t < end_time; t++) {
            m[{place, t}]++;
        }
    }

    int max_answer = 0;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > max_answer) max_answer = iter->second;
    }

    vector<pair<string, int>> v;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == max_answer) {
            v.push_back({ iter->first.first, iter->first.second });
        }
    }

    sort(v.begin(), v.end(), compare);


    int last = v.begin()->second;
    for (auto iter = v.begin() + 1; iter != v.end(); iter++) {
        if (iter->first == v.begin()->first && iter->second == last + 1) {
            last = iter->second;
        }
    }

    cout << v.begin()->first << ' ' << v.begin()->second << ' ' << last + 1;

    return 0;
}