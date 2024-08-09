#include <iostream>
#include <algorithm>
using namespace std;

string str;
string str_list[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    int len = str.length();
    for(int i=0; i < len; i++) {
        str_list[i] = str.substr(i, len);
    }

    sort(str_list, str_list + len);

    for(int i=0; i < len; i++) {
        cout << str_list[i] << '\n';
    }

    return 0;
}