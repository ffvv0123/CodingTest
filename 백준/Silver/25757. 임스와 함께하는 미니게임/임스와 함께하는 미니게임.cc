#include <iostream>
#include <set>
using namespace std;

int N;
char game;
set<string> name_list;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> game;

    for(int i=0; i < N; i++) {
        string name;
        cin >> name;
        name_list.insert(name);
    }

    if (game == 'Y') cout << name_list.size();
    else if(game == 'F') cout << name_list.size() / 2;
    else if(game == 'O') cout << name_list.size() / 3;

    return 0;
}