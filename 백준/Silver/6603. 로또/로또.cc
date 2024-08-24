#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<int> lotto, answer;
bool check[50];

void dfs() {
    if (answer.size() == 6) {
        for(int num : answer) {
            cout << num << " ";
        }
        cout << '\n';
        return;    
    }

    for(int i=0; i < k; i++) {
        if (!check[i] && (answer.empty() || lotto[i] > answer.back())) {
            check[i] = true;
            answer.push_back(lotto[i]);
            dfs();
            answer.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true) {
        cin >> k;
        if (k == 0) break;

        lotto.resize(k);
        for(int i=0; i < k; i++) cin >> lotto[i];

        dfs();
        cout << '\n';
    }

    return 0;
}