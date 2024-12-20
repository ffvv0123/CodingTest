/**
 * 연료를 최대 G 만큼 저장하는 탱크
 * 거리 1 이동에 연료 1 소모
 * D 만큼 이동할거임 -> D 만큼 연료 소모
 *
 * N개의 주유소 -> X[i]: 시작점에서 i번째 주유소의 거리
 * N개의 주유소 -> Y[i]: 시작점에서 i번째 주유소의 가격
 *
 * 연료는 B 들고 시작 -> 최소 연료를 구해봐라
 *
 * if 현재 주유소보다 싼 주유소에 갈 수 있으면 -> 거기 갈만큼만 주유 때림
 * else if 현재 보다 싼거 없거나, 너무 멀리 있다면 (연료 탱크 초과) -> G 풀로 채움
 * -> 이때는 최대한 덜 비싼걸로 최소한으로 채우는게 이득
 *
 * Next 배열로 다음 주유소를 관리함 (인덱스 저장)
 * -> next[i] = i 보다 멀리 있으면서 Y[i]보다 싼 가장 왼쪽의 주유소
 * if Next[i] 까지의 거리가 G 이하면 Next[i]로 이동
 * else G 초과하면 풀로 채우고 다음 주유소로
 *
 */
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, G, B, D;
long long ans;
pair <int, int> pos[50005]; // 위치, 비용
stack <pair<int, int>> s;   // 비용, index
int next_pos[50005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> G >> B >> D;
    for (int i = 1; i <= N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    N++;
    pos[N].first = D;
    pos[N].second = -1;
    sort(pos + 1, pos + N + 1);

    for (int i = N; i >= 1; i--) {
        while (!s.empty() && s.top().first >= pos[i].second) {
            s.pop();
        }
        if (s.empty()) next_pos[i] = -1;
        else next_pos[i] = s.top().second;
        s.push({pos[i].second, i});
    }

    for (int i = 1; i <= N; i++) {
        B -= pos[i].first - pos[i - 1].first;
        if (B < 0) {
            cout << -1;
            return 0;
        }

        int nextIndex = next_pos[i];
        // 더 싼 주유소가 없으면 목적지까지의 거리(D - pos[i].first)를 고려
        int distToCheaper = (nextIndex == -1) ? (D - pos[i].first) : (pos[nextIndex].first - pos[i].first);

        // 다음 더 싼 주유소(or 목적지)까지 도달하기 위해 필요한 연료량을 계산 (탱크 최대치 G 고려)
        int cost = min(G, distToCheaper);

        // 필요한 연료량 - 현재 연료량 만큼 주유
        if (cost > B) {
            ans += (cost - B) * 1LL * pos[i].second; 
            B = cost;
        }
    }

    cout << ans;

    return 0;
}