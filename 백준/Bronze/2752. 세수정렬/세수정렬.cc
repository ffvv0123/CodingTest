#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int max_value = max({a, b, c});
    int min_value = min({a, b, c});

    cout << min_value << " " << a + b + c - max_value - min_value << " " << max_value;

    return 0;
}