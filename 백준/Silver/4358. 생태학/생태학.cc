#include <iostream>
#include <map>
using namespace std;

map<string, int> tree;
int N = 0;
string tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(4);

    while (getline(cin, tmp)) {
        N++;
        tree[tmp]++;
    }

    for (auto iter : tree) {
        cout << iter.first << ' ' << (double)iter.second * 100 / N << '\n';
    }

    return 0;
}