#include <iostream>
#include <map>
using namespace std;

int N, answer = 0;
string A, B;
map<string, bool> dance;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> A >> B;
        if (A == "ChongChong" || B == "ChongChong") {
            dance[A] = true;
            dance[B] = true;
        }
        else if (dance[A]) dance[B] = true;
        else if (dance[B]) dance[A] = true;
    }

    for (auto iter : dance) {
        if (iter.second == 1) answer++;
    }

    cout << answer;

    return 0;
}