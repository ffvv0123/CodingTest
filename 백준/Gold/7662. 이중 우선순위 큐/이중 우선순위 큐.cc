/** Sol(1). 시간초과 엔딩 
 * DPQ -> 연산 명령에 따라 우선순위가 가장 높거나 낮은 데이터를 삭제
 * -> 삽입은 똑같음.
 * Q에 들어가는 값 자체를 우선순위로 가정.
 * -> 최종 max min 찾기.
 * 
 * -> list모두 나가리.
 */

#include <iostream>
#include <set>
using namespace std;

int T, k;
multiset<int> DPQ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        DPQ.clear();
        char order; int n;
        
        cin >> k;        
        for(int i=0; i < k; i++) {
            cin >> order >> n;

            if(order == 'I') {
                DPQ.insert(n);
            }
            else if (order == 'D'){
                if(!DPQ.empty()) {
                    if(n == 1) {
                        auto iter = DPQ.end();
                        iter--;
                        DPQ.erase(iter);
                    }
                    else if (n == -1) {
                        DPQ.erase(DPQ.begin());
                    }
                }
            }
        }

        if(DPQ.empty()) cout << "EMPTY\n";
        else cout << *DPQ.rbegin() << ' ' << *DPQ.begin() << '\n';
    }

    return 0;
}
