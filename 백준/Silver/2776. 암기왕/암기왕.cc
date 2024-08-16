#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, M, tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        vector<int> num;

        cin >> N;
        num.resize(N);

        for(int i=0; i < N; i++) {
            cin >> num[i];
        }

        sort(num.begin(), num.end());
        
        cin >> M;
        for(int i=0; i < M; i++) {
            cin >> tmp;
            if (binary_search(num.begin(), num.end(), tmp)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}