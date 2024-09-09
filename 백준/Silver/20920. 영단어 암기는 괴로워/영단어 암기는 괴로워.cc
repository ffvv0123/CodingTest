#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string tmp;
map<string, int> word;

bool compare(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        else return a.first.length() > b.first.length();
    }
    else return a.second > b.second;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    while (N--) {
        cin >> tmp;
        if (tmp.length() < M) continue;

        word[tmp]++;
    }

    vector<pair<string, int>> v;
    for (auto& it : word) v.push_back(it);

    sort(v.begin(), v.end(), compare);

    for (auto& it : v) {
        cout << it.first << '\n';
    }

    return 0;
}