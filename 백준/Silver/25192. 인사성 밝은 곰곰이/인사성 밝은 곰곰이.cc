#include <iostream>
#include <set>
using namespace std;

int N, answer = 0;
string input;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> nickname;

    cin >> N;
    while(N--) {
        cin >> input;
        if (input == "ENTER") {
            answer += nickname.size();
            nickname.clear();
        }
        else {
            nickname.insert(input);
        }
    }
    answer += nickname.size();

    cout << answer;

    return 0;
}