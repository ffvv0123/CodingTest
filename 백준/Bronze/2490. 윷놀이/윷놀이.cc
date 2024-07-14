#include <iostream>
using namespace std;

string game(int arr[]) {
    int count_0 = 0;
    for(int i=0; i < 4; i++){
        if (arr[i] == 0) count_0++;
    }
    if (count_0 == 1) return "A";
    else if (count_0 == 2) return "B";
    else if (count_0 == 3) return "C";
    else if (count_0 == 4) return "D";
    else if (count_0 == 0) return "E";

    return "";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i < 3; i++) {
        int game_list[4];

        for(int j=0; j < 4; j++)
            cin >> game_list[j];

        cout << game(game_list) << '\n';
    }

    return 0;
}