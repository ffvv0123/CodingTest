/**
 * 입력: N M K
 * N개 중, 앞면에 O가 M개, X가 N-M개
 * 뒷면에는 O가 K개, X가 N-K개
 * -> OO, XX 쌍 최대로
 * 
 * O -> M개 
 * X -> N-M개
 * 
 * O -> K개
 * X -> N-K개
 * 
 * min(M,K) + min(N-M, N-K)
 * 
 */

#include <iostream>
using namespace std;

int N, M, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    cout << min(M, K) + min(N-M, N-K);

    return 0;
}