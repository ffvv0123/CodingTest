#include <iostream>
using namespace std;

int section(int level) {
    if (level == 300) return 1;
    else if (level >= 275) return 2;
    else if (level >= 250) return 3;
    else return 4;
}

int main() {
    int N, tmp;

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> tmp;
        cout << section(tmp) << ' ';
    }

    return 0;
}