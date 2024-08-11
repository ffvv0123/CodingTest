#include <iostream>
#include <list>
using namespace std;

string S;
int M;
char cmd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    list<char> editor;

    cin >> S;
    auto cursor = editor.end();
    

    for(int i=0; i < S.length(); i++) {
        editor.push_back(S[i]);
    }

    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor == editor.begin()) continue;
            cursor--;
        }
        else if (cmd == 'D') {
            if (cursor == editor.end()) continue;
            cursor++;
        }
        else if (cmd == 'B') {
            if (cursor == editor.begin()) continue;
            cursor--;
            cursor = editor.erase(cursor);
        }
        else if (cmd == 'P') {
            cin >> cmd;
            editor.insert(cursor, cmd);
        }
    }

    for(auto i : editor) cout << i;

    return 0;
}