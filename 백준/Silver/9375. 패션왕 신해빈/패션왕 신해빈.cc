/**
 * 
 * n개의 카테고리에서 각각 ki개의 아이템이 있다.
 * -> 문제에서 요구하는 경우의 수: {PI i=1->n (ki + 1)} - 1
 */

#include <iostream>
#include <map>
using namespace std;

int t, n;
int answer;
string costume, type;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        map<string, int> fashion;
        answer = 1;

        cin >> n;
        for(int i=0; i < n; i++) {
            cin >> costume >> type;
            fashion[type]++;
        }

        for(auto iter = fashion.begin(); iter != fashion.end(); iter++) {
            answer *= (iter->second + 1);
        }
        answer--;

        cout << answer << '\n';
    }

    return 0;
}