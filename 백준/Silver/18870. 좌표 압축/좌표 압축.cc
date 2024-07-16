#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<int> X(N);

    for(int i=0; i < N; i++)
        cin >> X[i];
    
    vector<int> CX(X);
    sort(CX.begin(), CX.end());

    CX.erase(unique(CX.begin(), CX.end()), CX.end());

    for(int i=0; i < N; i++) {
        auto it = lower_bound(CX.begin(), CX.end(), X[i]);
        cout << it - CX.begin() << ' ';
    }
    
    return 0;
}

/**
 * vector<int> v;
 * vector<int> cv(v); // copy vector v
 * 
 * lower_bound, upper_bound -> c++의 이진탐색 함수
 * -> lower_bound(start, end, key) // 정렬이 되어있다는 가정!
 */